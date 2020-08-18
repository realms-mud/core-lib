//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/secure/simulated-efuns/database.c";

private object *CannedUserList = ({});
private object RestoreCaller = 0;
private int isInteractive = 1;
private string *TestingGroups = ({ });
private int ShortCircuitCallOuts;

/////////////////////////////////////////////////////////////////////////////
public nomask int testingInteractive()
{
    return isInteractive;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void ToggleInteractive()
{
    isInteractive = !isInteractive;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setUpForTesting()
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask object *cannedUserList()
{
    return CannedUserList;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setUsers(object *list)
{
    foreach(object item in list)
    {
        this_object()->addUser(item);
    }
    CannedUserList = list;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object restoreCaller()
{
    return RestoreCaller;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRestoreCaller(object restorer)
{
    if (objectp(restorer))
    {
        RestoreCaller = restorer;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *testingGroups()
{
    return TestingGroups;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCustomGroups(string *list)
{
    TestingGroups = list + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask void ToggleCallOutBypass()
{
    ShortCircuitCallOuts = !ShortCircuitCallOuts;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void call_out(string method, int delay, varargs mixed *data)
{
    if (ShortCircuitCallOuts && previous_object())
    {
        apply(#'call_direct,previous_object(),method,data);
    }
    else
    {
        apply(#'efun::call_out,method,delay,data);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int exec(object newObject, object oldObject)
{
    printf("Exec of %O to %O.\n", oldObject, newObject);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void validateTestDatabase()
{
    int dbHandle = efun::db_connect(RealmsDatabase());

    createDatabase(dbHandle);
    migrateDatabase(dbHandle, 1, DatabaseVersion());

    db_close(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int DatabaseVersionFromDatabase()
{
    int dbHandle = efun::db_connect(RealmsDatabase());

    string query = "select id from versionInfo "
        "where versionType = 'database' order by id desc limit 1;";

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    db_close(dbHandle);

    return (result && result[0]) ? to_int(result[0]) : 0;
}
