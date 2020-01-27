//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask string authenticateUser(string userName, string password)
{
    string ret = "error";
    string query = sprintf("select authenticateUser('%s', '%s');",
        sanitizeString(userName), sanitizeString(password));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result && pointerp(result) && result[0])
    {
        ret = convertString(result[0]);
    }
    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int userExists(string userName)
{
    int ret = 0;
    string query = sprintf("select id from users where login = '%s';",
        sanitizeString(userName));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result && result[0])
    {
        ret = 1;
    }
    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createUser(string userName, string password, 
    string address)
{
    string query = sprintf("call createUser('%s', '%s', '%s');",
        sanitizeString(userName), 
        sanitizeString(password), 
        sanitizeString(address));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addressTemporarilyBanished(string address)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void temporarilyBanIP(string address)
{

}
