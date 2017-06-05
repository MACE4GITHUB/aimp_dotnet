param(
    [string] $configuration = "Debug"
)
################################################################################################
# Usage:
# Run build.ps1
#   [-configuration Configuration]: Default to be Release
#   [-raw]: If it's set, the build process will skip updating template
#   [-prod]: If it's set, the build process will update version
################################################################################################

$ErrorActionPreference = 'Stop'
$releaseBranch = "master"
$gitCommand = "git"
$npmCommand = "c:\nodejs\npm.cmd"
$nodeCommand = "c:\nodejs\node.exe"
$gulpCommand = ".\node_modules\.bin\gulp.cmd"
$packageVersion = "1.0.0"
$assemblyVersion = "1.0.0.0"

$scriptPath = $MyInvocation.MyCommand.Path
$scriptHome = Split-Path $scriptPath
$versionCsFolderPath = $scriptHome + "\TEMP\"
$docfxCommand = "$env:LOCALAPPDATA\docfx\docfx.exe"
$docFile = Join-Path $scriptHome "docfx.json"

Push-Location $scriptHome

function ProcessLastExitCode {
    param($exitCode, $msg)
    if ($exitCode -eq 0) {
        Write-Host "Success: $msg
        " -ForegroundColor Green
    }
    else {
        Write-Host "Error $($exitCode): $msg
        " -ForegroundColor Red
        Pop-Location
        Exit 1
    }
}

function ValidateCommand {
    param($command)
    return (Get-Command $command -ErrorAction SilentlyContinue) -ne $null
}

# Check is docfx.exe exists
if (-not(ValidateCommand($docfxCommand))) {
	Write-Host "Downloading DocFX package..."
	New-Item -Path "$env:LOCALAPPDATA\DocFX" -Type directory -Force | Out-Null
	$ProgressPreference = 'SilentlyContinue'
	[Net.WebRequest]::DefaultWebProxy.Credentials = [Net.CredentialCache]::DefaultCredentials
	$outFile = "$env:LOCALAPPDATA\docfx\docfx.zip"
	
    Invoke-WebRequest 'https://github.com/dotnet/docfx/releases/download/2.16.4/docfx.zip' -OutFile $outFile
    ProcessLastExitCode 0 "Extract docfx.zip"
	Add-Type -AssemblyName System.IO.Compression.FileSystem
	[System.IO.Compression.ZipFile]::ExtractToDirectory("$outFile", "$env:LOCALAPPDATA\DocFX")
}


# Update submodules
if (-not(ValidateCommand($gitCommand))) {
	ProcessLastExitCode 1 "Git is required however it is not installed."
}

if (-not(ValidateCommand($npmCommand))) {
	Write-Host "Npm is required however it is not installed.
	" -ForegroundColor Red
	
	Write-Host "Download node-v6.10.3-x64.msi
	" -ForegroundColor Green
	
	if (-not(Test-Path "$env:LOCALAPPDATA\Temp"))
	{	
		New-Item -Path "$env:LOCALAPPDATA\Temp" -Type directory | Out-Null
	}
	
	$outFile = "$env:LOCALAPPDATA\Temp\node-v6.10.3-x64.msi"
	Invoke-WebRequest 'https://nodejs.org/dist/v6.10.3/node-v6.10.3-x64.msi' -OutFile $outFile
	
	& msiexec /a $outFile /qn
	
	Start-Sleep -s 30
}

Write-Host "Update Path environment
" -ForegroundColor Green
$env:Path += ";c:\nodejs\"

#Write-Host "Updating submodules..."
#& $gitCommand submodule update --init
#Write-Host "Submodules updated" -ForegroundColor Green

#if (-not(Get-Module -ListAvailable -Name Invoke-MsBuild)){
#	Write-Host "Install requeried powershell modules..."
#	Install-Module -Name Invoke-MsBuild -Scope CurrentUser
#}

#foreach ($sln in (Get-ChildItem "aimp_dotnet/AIMP.SDK/AIMP.SDK.csproj")) {
#    Write-Host "Start building $($sln.FullName)"
#	$buildSucceeded = Invoke-MsBuild -Path $sln.FullName -MsBuildParameters "/target:Clean;Build /property:Configuration=$configuration"
#	if ($buildSucceeded) {
#		ProcessLastExitCode $lastexitcode "Invoke-MsBuild -Path $($sln.FullName) -MsBuildParameters /target:Clean;Build /property:Configuration=$($configuration)"
#	}
#}

Write-Host "Build succeeds." -ForegroundColor Green

Write-Host "Install npm dependencies"
& $npmCommand install --save-dev

Write-Host "Install bower dependencies"
& $nodeCommand .\node_modules\bower\bin\bower install

Write-Host "Execute gulp task 'default'"
& $gulpCommand default


Write-Host "Starting generate documentation"
if (-not($docFile)) {
	ProcessLastExitCode 1 "$($docFile) not found."
}

& $docfxCommand $docFile

Pop-Location