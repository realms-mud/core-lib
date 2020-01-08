//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include <driver_hook.h>

/////////////////////////////////////////////////////////////////////////////
static nomask string includeDirectories(string includeFile, string currentFile)
{
    string ret = file_size(includeFile) ? includeFile : 0;

    if (!ret)
    {
        string *locations = ({ "/include", "/lib/include", "/sys" });
        foreach(string location in locations)
        {
            string name = sprintf("%s/%s", location, includeFile);
            if (file_size(name))
            {
                ret = name;
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void moveHook(object item, object destination)
{
    if (objectp(item) && objectp(destination))
    {
        efun::set_environment(item, destination);

        if (living(item))
        {
            efun::set_this_player(item);
            destination->init();

            if (!item)
            {
                raise_error(sprintf("Destination (%O) init() call "
                    "destructed moved item.\n", destination));
            }
        }

        if (environment(item) == destination)
        {
            object *otherItems = all_inventory(destination) - ({ item });
            foreach(object otherItem in otherItems)
            {
                if (living(otherItem))
                {
                    efun::set_this_player(otherItem);
                    item->init();
                }
                if (!item)
                {
                    raise_error(sprintf("(%O) init() call "
                        "destructed moved item.\n", item));
                }
            }

            if (living(item))
            {
                efun::set_this_player(item);
                filter_objects(otherItems, "init");
            }
            if (living(destination) && item)
            {
                efun::set_this_player(destination);
                item->init();
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mixed loadUIDs(string objectName, object previousObject)
{
    string uid = 0;

    if (sizeof(regexp(({ objectName }), "^/*players")))
    {
        uid = regreplace(objectName, "^/*players/([^/]+)/.*", "\\1", 1);
    }

    if (!uid && previousObject)
    {
        uid = getuid(previousObject);
    }
    return uid ? uid : 1;
}

/////////////////////////////////////////////////////////////////////////////
static nomask mixed cloneUIDs(object blueprint, string name, 
    object previousObject)
{
    return getuid(blueprint) || getuid(previousObject) || 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addDriverHooks()
{
    // Set up the move hook
    set_driver_hook(H_MOVE_OBJECT0,
        unbound_lambda( ({'item, 'dest}),
            ({#'moveHook, 'item, 'dest })
        )
    );

    // Load UIDs hook
    set_driver_hook(H_LOAD_UIDS,
        unbound_lambda( ({'object_name}), ({
            #'loadUIDs, 'object_name, ({#'previous_object}) })
        )
    );

    // Clone UIDs hook
    set_driver_hook(H_CLONE_UIDS,
        unbound_lambda( ({ 'blueprint, 'new_name}), ({
            #'cloneUIDs, 'blueprint, 'new_name, ({#'previous_object}) })
        )
    );

    // Various create / clone hooks
    set_driver_hook(H_CREATE_SUPER, "reset");
    set_driver_hook(H_CREATE_OB,    "reset");
    set_driver_hook(H_CREATE_CLONE, "reset");

    set_driver_hook(H_RESET,        "reset");
    set_driver_hook(H_CLEAN_UP,     "clean_up");

    // Add directional abbreviations
    set_driver_hook(H_MODIFY_COMMAND, ([ 
        "e":"east", "w":"west", "s":"south", "n":"north", "d":"down", 
        "u":"up", "nw":"northwest", "ne":"northeast", "sw":"southwest", 
        "se":"southeast" ]));

    set_driver_hook(H_MODIFY_COMMAND_FNAME, "modify_command");
    set_driver_hook(H_NOTIFY_FAIL, "What?\n");

    // Add system include directories
    set_driver_hook(H_INCLUDE_DIRS, 
        unbound_lambda( ({'included, 'file}),
            ({#'includeDirectories,'included,'file }) 
        )
    );

    set_driver_hook(H_AUTO_INCLUDE,
    "#pragma pedantic\n"
    "#pragma warn_rtt_checks\n");
}
