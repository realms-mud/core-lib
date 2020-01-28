//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask void movePlayerToStart(object player)
{
    object startingLocation = 0;
    catch (startingLocation = load_object(player->savedLocation()));

    if (startingLocation)
    {
        startingLocation->enterEnvironment(player);
    }
    else
    {
        startingLocation = load_object("/areas/eledhel/southern-city/12x2.c");
        startingLocation->enterEnvironment(player);

        tell_object(player, "Doh! The room you were last in during your "
            "previous session is broken.\nYou have been moved to a different "
            "location.\n");
    }

    say(sprintf("%s has arrived.\n", player->Name()));
}

/////////////////////////////////////////////////////////////////////////////
private nomask object checkIfPlayerObjectExists(string name)
{
    object ret = 0;

    object *playersWithName = filter(users(), (: $1->RealName() == $2 :), name);

    if (sizeof(playersWithName))
    {
        ret = playersWithName[0];
        if (member(inherit_list(ret), "lib/realizations/player.c") < 0)
        {
            ret = 0;
        }
        if (ret)
        {
            movePlayerToStart(ret);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object loadNewPlayerObject(string name)
{
    object ret = 0;
    object dataAccess = load_object("/lib/modules/secure/dataAccess.c");
    switch (dataAccess->playerType(name))
    {
        case "owner":
        case "god":
        case "demigod":
        case "archwizard":
        case "sage":
        case "elder":
        case "admin":
        case "senior":
        case "highwizard":
        case "emeritus":
        case "creator":
        case "wizard":
        case "apprentice":
        {
            ret = clone_object("/lib/realizations/wizard.c");
            ret->restore(name);
            ret->updateLoginTime();
            movePlayerToStart(ret);
            break;
        }
        default:
        {
            ret = clone_object("/lib/realizations/player.c");
            ret->registerEvent(clone_object(
                "/lib/modules/creation/initializePlayer.c"));
            ret->restore(name);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reportUserLogin(object user)
{
    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    if (channels)
    {
        string address = query_ip_number(user) || "???";
        channels->registerUser(user);
        channels->broadcastMessage("status", sprintf("%s (%s) has joined"
            " the game.\n", capitalize(user->RealName()), address), user);
        user->setProperty("IP address", address);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getPlayerObject(string name)
{
    object ret = checkIfPlayerObjectExists(name);
    if (!ret)
    {
        ret = loadNewPlayerObject(name);
    }

    call_out("reportUserLogin", 1, ret);
    return ret;
}
