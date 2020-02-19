//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask string convertString(string input)
{
    string ret = input;
    if (!stringp(input))
    {
        ret = "";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int connect()
{
    int ret = 0;

    if (!sizeof(db_handles()))
    {
        ret = db_connect(RealmsDatabase());
    }
    else
    {
        ret = db_handles()[0];
    }
    if (db_error(ret))
    {
        getDictionary("log")->log("DBERROR", 
            sprintf("%s:\n%s\n%s\nCall stack:%O\n", ctime(time()),
            db_error(ret), "Connecting to database", caller_stack()));
    }

    if (ret)
    {
        db_exec(ret, "use " + RealmsDatabase() + ";");
    }

    while (db_fetch(ret));
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void disconnect(int handle)
{
    while(db_fetch(handle));
    db_close(handle);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string sanitizeString(string value)
{
    if (!value)
    {
        value = "";
    }
    
    return db_conv_string(value);
}
