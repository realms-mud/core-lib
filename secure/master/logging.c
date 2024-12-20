//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private nomask object logDictionary = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask string get_wiz_name(string file)
{
    string ret = 0;
    string wizardName, restOfPath;

    if (sizeof(regexp(({ file }), "^/*players/[^/]/")))
    {
        ret = regreplace(file, "^/*players/([^/]+)/.*", "\\1", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void log_error(string file, string message)
{
    string logName = get_wiz_name(file);
    if (!logName)
    {
        logName = "log";
    }

    if (!logDictionary)
    {
        logDictionary =
            load_object("/secure/simul_efun.c")->getDictionary("log");
    }

    logDictionary->log(logName, message);
}
