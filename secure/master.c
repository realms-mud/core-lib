//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/secure/master/command-parser.c";
virtual inherit "/secure/master/connect.c";
virtual inherit "/secure/master/destruct.c";
virtual inherit "/secure/master/hooks.c";
virtual inherit "/secure/master/logging.c";
virtual inherit "/secure/master/preload.c";
virtual inherit "/secure/master/security.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void inaugurate_master(int arg)
{
    addDriverHooks();
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed get_master_uid()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string get_simul_efun()
{
    string simulEfunName = "/secure/simul_efun.c";
    object simulEfun;
    
    string failure = catch(
        simulEfun = load_object(simulEfunName)
    );

    if (failure)
    {
        printf("Failed to load simul_efun: %O\n", failure);
        shutdown();
        simulEfunName = 0;
    }
    else
    {
        simulEfun->start_simul_efun();
    }

    return simulEfunName;
}

/////////////////////////////////////////////////////////////////////////////
public void runtime_error(string error, string program, 
    string currentObject, int line)
{
    if (this_player() && interactive(this_player()))
    {
        string message = "Your sensitive mind notices a wrongness in the "
            "fabric of space.\n";

        if (member(inherit_list(this_player()),
            "/lib/realizations/wizard.c") > -1)
        {
            message = currentObject ?
                sprintf("%s, program: %O, object: %O line %d\n",
                    error, program, currentObject, line) : error;
        }

        catch (
            write(message)
        );
    }
}
