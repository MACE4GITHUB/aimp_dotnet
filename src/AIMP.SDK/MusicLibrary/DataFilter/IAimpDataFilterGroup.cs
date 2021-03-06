﻿// ----------------------------------------------------
// 
// AIMP DotNet SDK
// 
// Copyright (c) 2014 - 2019 Evgeniy Bogdan
// https://github.com/martin211/aimp_dotnet
// 
// Mail: mail4evgeniy@gmail.com
// 
// ----------------------------------------------------
namespace AIMP.SDK.MusicLibrary.DataFilter
{
    public enum FilterGroupOperationType
    {
        OR,
        AND,
        NOTOR,
        NOTAND
    }

    /// <summary>
    /// Provides an ability to group few filters.
    /// </summary>
    public interface IAimpDataFilterGroup
    {
        /// <summary>
        /// Gets or sets the rule processing results from subsidiaries filters.
        /// </summary>
        FilterGroupOperationType Operation { get; set; }

        /// <summary>
        /// Adds the new child filter to the group.
        /// </summary>
        /// <param name="field">The field name.</param>
        /// <param name="value1">The value1.</param>
        /// <param name="value2">The value2.</param>
        /// <param name="operation">The rule processing results from subsidiaries filters.</param>
        /// <param name="filter">[out] The added filter.</param>
        AimpActionResult Add(string field, object value1, object value2, FieldFilterOperationType operation, out IAimpDataFieldFilter filter);

        AimpActionResult Add(string field, object[] values, int count, out IAimpDataFieldFilterByArray filter);

        /// <summary>
        /// Adds the child group.
        /// </summary>
        /// <param name="group">The group.</param>
        AimpActionResult AddGroup(out IAimpDataFilterGroup group);

        /// <summary>
        /// Clears the filter.
        /// </summary>
        AimpActionResult Clear();

        /// <summary>
        /// Deletes the filter by specified index.
        /// </summary>
        /// <param name="index">The index.</param>
        AimpActionResult Delete(int index);

        /// <summary>
        /// Gets the child group by index.
        /// </summary>
        /// <param name="index">The index.</param>
        /// <param name="group">The filter group <seealso cref="IAimpDataFilterGroup"/>.</param>
        /// <returns>Operation result <seealso cref="AimpActionResult"/></returns>
        AimpActionResult GetChild(int index, out IAimpDataFilterGroup group);

        /// <summary>
        /// Gets the child field filter by index.
        /// </summary>
        /// <param name="index">The index.</param>
        /// <param name="fieldFilter">The field filter <seealso cref="IAimpDataFieldFilter"/>.</param>
        /// <returns>Operation result <seealso cref="AimpActionResult"/></returns>
        AimpActionResult GetChild(int index, out IAimpDataFieldFilter fieldFilter);

        /// <summary>
        /// Gets the child count.
        /// </summary>
        int GetChildCount();

        void BeginUpdate();

        void EndUpdate();
    }
}