//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/object_info.h"

virtual inherit "/secure/simulated-efuns/database.c";
virtual inherit "/secure/simulated-efuns/group-management.c";
virtual inherit "/secure/simulated-efuns/interactive-info.c";
virtual inherit "/secure/simulated-efuns/object-info.c";
virtual inherit "/secure/simulated-efuns/services.c";
virtual inherit "/secure/simulated-efuns/strings.c";
virtual inherit "/secure/simulated-efuns/users.c";
//virtual inherit "/secure/simulated-efuns/testing.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void start_simul_efun()
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask string version()
{
    return regreplace(__VERSION__, "^([0-9]+.[0-9]+.[0-9]+).*$", "\\1", 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object find_object(string objectName)
{
    return efun::find_object(objectName);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void shutdown()
{
    map(efun::db_handles(), #'db_close); // closes all other orphaned db handles

        string previousObject = object_name(previous_object());

    if (member(({ "/secure/master", "/lib/commands/wizard/reboot" }), 
        previousObject) > -1)
    {
        efun::shutdown();
    }
    else if (this_player() && interactive(this_player()) &&
        (member(inherit_list(this_player()),
            "/lib/realizations/wizard.c") > -1) &&
            (member(this_player()->groups(), "elder") > -1))
        efun::shutdown();
    return;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void set_environment(object ob)
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void set_this_player(object ob)
{
    if (member(inherit_list(this_object()),
        "/secure/simulated-efuns/testing.c") > -1)
    {
        efun::set_this_player(ob);
    }
}

#if ! __EFUN_DEFINED__(enable_commands)

/////////////////////////////////////////////////////////////////////////////
public nomask void enable_commands()
{
    object ob = efun::previous_object();

    efun::configure_object(ob, OC_COMMANDS_ENABLED, 1);
    efun::set_this_player(ob);
}

#endif

#if ! __EFUN_DEFINED__(disable_commands)

/////////////////////////////////////////////////////////////////////////////
public nomask void disable_commands()
{
    object ob = efun::previous_object();

    efun::configure_object(ob, OC_COMMANDS_ENABLED, 0);
    efun::set_this_player(0);
}

#endif

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}
