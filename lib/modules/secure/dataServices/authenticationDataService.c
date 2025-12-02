//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public nomask int characterExists(string name)
{
    int ret = 0;
    string query = sprintf("select id from players where name = '%s';",
        sanitizeString(name));

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
public nomask string *getCharacters(string userName)
{
    string *ret = ({});
    string query = sprintf("select name from players "
        "inner join users on users.id = players.userId "
        "where login = '%s';",
        sanitizeString(userName));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = 0;
    do
    {
        result = db_fetch(dbHandle);

        if (result && result[0])
        {
            ret += ({ result[0] });
        }
    } while (result);

    disconnect(dbHandle);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void saveUser(string userName, string password, 
    string address)
{
    string query = sprintf("select saveUser('%s', '%s', '%s');",
        sanitizeString(userName), 
        sanitizeString(password), 
        sanitizeString(address));

    int dbHandle = connect();
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeCharacter(string name)
{
    int ret = 0;
    if (objectp(previous_object()) &&
        sizeof(regexp(({ object_name(previous_object()) }), 
            "^/*secure/master")))
    {
        string query = sprintf("call removePlayer('%s');",
            sanitizeString(name));

        int dbHandle = connect();
        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);

        disconnect(dbHandle);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int setWizardLevel(string name, string level)
{
    int ret = 0;
    if (objectp(previous_object()) &&
        sizeof(regexp(({ object_name(previous_object()) }),
            "^/*secure/master")))
    {
        string query = sprintf("select setWizardLevel('%s', '%s');",
            sanitizeString(name),
            sanitizeString(level));

        int dbHandle = connect();
        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
        ret = result && (to_int(result[0]) > 0);

        disconnect(dbHandle);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int demoteWizardToPlayer(string target, string sponsor)
{
    int ret = 0;
    if (objectp(previous_object()) &&
        sizeof(regexp(({ object_name(previous_object()) }),
            "^/*secure/master")))
    {
        string query = sprintf("select demoteWizardToPlayer('%s', '%s');",
            sanitizeString(target),
            sanitizeString(sponsor));

        int dbHandle = connect();
        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
        ret = result && (to_int(result[0]) > 0);

        disconnect(dbHandle);
    }
    return ret;
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
