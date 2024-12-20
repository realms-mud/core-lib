//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *getIssues(string whereClause)
{
    mapping *ret = 0;
    string query = sprintf("select * from issues %s " 
        "order by firstLoggedTime desc;", whereClause);

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (sizeof(result))
        {
            mapping entry = ([]);
            entry["id"] = to_int(result[0]);
            entry["status"] = to_int(result[1]);
            entry["logged by"] = convertString(result[2]);
            entry["assigned to"] = convertString(result[3]);
            entry["first logged time"] = convertString(result[4]);
            entry["affected object"] = convertString(result[5]);
            entry["location"] = convertString(result[6]);
            entry["data"] = convertString(result[7]);

            ret += ({ entry });
        }
    }  while (result);
    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getNewlySubmittedIssues()
{
    return getIssues("where status = 0");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getIssuesByPlayerName(string playerName)
{
    return getIssues(sprintf("where loggedBy = '%s'", playerName));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getIssuesByWizard(string wizard)
{
    return getIssues(sprintf("where assignedTo = '%s'", wizard));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateIssueData(mapping data)
{
    return member(data, "status") &&
        member(data, "logged by") &&
        member(data, "affected object") &&
        member(data, "location") &&
        member(data, "data");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveIssue(mapping data)
{
    string query = sprintf("call saveIssue(%d, %d, '%s', '%s', '%s', '%s', '%s');",
        data["id"],
        data["status"],
        sanitizeString(data["logged by"]),
        sanitizeString(data["assigned to"]),
        sanitizeString(data["affected object"]),
        sanitizeString(data["location"]),
        sanitizeString(data["data"]));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);
    disconnect(dbHandle);
}
