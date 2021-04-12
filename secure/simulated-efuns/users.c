//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/configuration.h"

private mapping livingObjects = ([]);
private mapping players = ([]);
private mapping wizards = ([]);
private mapping guests = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int interactive(object user)
{
    return (member(inherit_list(this_object()),
        "/secure/simulated-efuns/testing.c") > -1) ? 
        this_object()->testingInteractive() :
        efun::interactive(user);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addUser(object user)
{
    if (objectp(user) && interactive(user) && previous_object() &&
        (interactive(previous_object()) ||
            sizeof(regexp(({ program_name(previous_object()) }),
                "^/*(lib/modules/secure|secure)"))))
    {
        if (member(inherit_list(user), "/lib/realizations/wizard.c") > -1)
        {
            wizards[lower_case(user->RealName())] = user;
        }
        else if (member(inherit_list(user), "/lib/realizations/player.c") > -1)
        {
            players[lower_case(user->RealName())] = user;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void pruneLivingObjects()
{
    string *livingToPrune = filter(m_indices(livingObjects), 
        (: !objectp($2[$1]) :), livingObjects);

    foreach(string item in livingToPrune)
    {
        m_delete(livingObjects, item);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addLiving(object creature)
{
    if ((member(inherit_list(creature), "/lib/realizations/wizard.c") > -1) ||
        (member(inherit_list(creature), "/lib/realizations/player.c") > -1))
    {
        addUser(creature);
    }
    else if((member(inherit_list(creature), 
        "/lib/realizations/living.c") > -1) && living(creature))
    {
        livingObjects[lower_case(creature->Name())] = creature;
        call_out("pruneLivingObjects", 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object findPlayer(string name)
{
    object ret = 0;
    name = lower_case(name);

    if (member(players, name))
    {
        if (objectp(players[name]) && interactive(players[name]))
        {
            ret = players[name];
        }
        else
        {
            m_delete(players, name);
        }
    }

    if (!ret && member(wizards, name))
    {
        if (objectp(wizards[name]) && interactive(wizards[name]))
        {
            ret = wizards[name];
        }
        else
        {
            m_delete(wizards, name);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object findLiving(string name)
{
    name = lower_case(name);
    object ret = findPlayer(name);

    if (!ret && member(livingObjects, name))
    {
        if (objectp(livingObjects[name]))
        {
            ret = livingObjects[name];
        }
        else
        {
            pruneLivingObjects();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *users()
{
    object *ret = filter(efun::users(),
        (: !function_exists("isInvisibleToCaller", $1) ||
            (function_exists("isInvisibleToCaller", $1) && $2 &&
            !$1->isInvisibleToCaller($2)) :), previous_object());

    if (member(inherit_list(this_object()),
        "/secure/simulated-efuns/testing.c") > -1)
    {
        ret = call_direct(this_object(), "cannedUserList");
    }
    return ret - ({ 0 });
} 

/////////////////////////////////////////////////////////////////////////////
private nomask object *usersFromMapping(mapping userMapping)
{
    object *ret = ({});

    if (previous_object() && (member(inherit_list(previous_object()),
        "/secure/login.c") > -1) && sizeof(userMapping))
    {
        ret = m_values(userMapping);
    }
    return ret - ({ 0 });
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *players()
{
    return usersFromMapping(players);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *wizards()
{
    return usersFromMapping(wizards);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeCharacter(object character)
{
    object userManagement = load_object("/secure/master/user-management.c");

    return userManagement ? userManagement->removeCharacter(character) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int createWizard(string wizardName, string level)
{
    object userManagement = load_object("/secure/master/user-management.c");

    return userManagement ?
        userManagement->createWizard(wizardName, level) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int demoteWizardToPlayer(string wizardName)
{
    object userManagement = load_object("/secure/master/user-management.c");

    return userManagement ?
        userManagement->demoteWizardToPlayer(wizardName) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string StartLocation()
{
    return "/areas/eledhel/southern-city/12x2.c";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getGuestName(object player)
{
    if (!sizeof(guests))
    {
        for (int i = 1; i < 100; i++)
        {
            guests[sprintf("guest%02d", i)] = 0;
        }
    }

    string *possibleNames = sort_array(filter(m_indices(guests),
        (: !objectp($2[$1]) :), guests), (: $1 > $2 :));

    string guestName = sizeof(possibleNames) ? possibleNames[0] :
        "guest";
    guests[guestName] = player;

    return guestName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void configureCharset(object player, string charset)
{
    if (efun::interactive(player))
    {
        if (charset == "unicode")
        {
            configure_interactive(player, IC_ENCODING, "UTF-8//TRANSLIT");
        }
        else
        {
            configure_interactive(player, IC_ENCODING, "ISO8859-1//TRANSLIT");
        }
    }
}
