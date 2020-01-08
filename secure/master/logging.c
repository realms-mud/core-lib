//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/*
 * Get the owner of a file. This is called from the game driver, so as
 * to be able to know which wizard should have the error.
 */
string get_wiz_name(string file)
{
    string name, rest;

    if (sscanf(file, "players/%s/%s", name, rest) == 2)
    {
        return name;
    }
    return 0;
}

/*
 * Write an error message into a log file. The error occured in the object
 * 'file', giving the error message 'message'.
 */
void log_error(string file, string message)
{
    string name;
 
    name = get_wiz_name(file);
     if (!name)
         name = "log";
    "secure/simul_efun"->log_file(name, message);   
    "secure/dblog"->log_error(previous_object(),"",0,message);
}
 