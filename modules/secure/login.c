//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask object checkIfPlayerObjectExists(string name)
{
    object ret = 0;

    if (objectp(find_player(name)))
    {
        ret = find_player(name);
        if (!query_once_interactive(ret))
        {
            ret = 0;
        }
        if (ret)
        {
            move_object(ret, ret->savedLocation());
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
        case "creator":
        case "wizard":
        case "apprentice":
        {
            ret = clone_object("/lib/realizations/wizard.c");
            ret->restore(name);
            move_object(ret, ret->savedLocation());
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
public nomask object getPlayerObject(string name)
{
    object ret = checkIfPlayerObjectExists(name);
    if (!ret)
    {
        ret = loadNewPlayerObject(name);
    }
    return ret;
}