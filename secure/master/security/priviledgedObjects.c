//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#pragma no_clone
#pragma no_inherit

private mapping priviledgedObjects = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask void Initialize()
{
    string *priviledgedList = get_dir("/secure/master/security/", 0x10) -
        ({ "secure/master/security/priviledgedObjects.c",
            "secure/master/security/priviledgeGroup.c" });

    foreach(string priviledgeGroup in priviledgedList)
    {
        object priviledgedObject = load_object(priviledgeGroup);

        priviledgedObjects[priviledgedObject->name()] = priviledgedObject;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasPermission(string path, string method, object caller,
    string permissionType)
{
    int ret = 0;

    if (!sizeof(priviledgedObjects))
    {
        Initialize();
    }

    string key = object_name(caller);
    object permission;

    if (member(priviledgedObjects, key) && objectp(priviledgedObjects[key]))
    {
        permission = priviledgedObjects[key];
    }
    else
    {
        string *inheritedItems = inherit_list(caller);
        foreach(string potentialItem in inheritedItems)
        {
            if (member(priviledgedObjects, potentialItem) &&
                objectp(priviledgedObjects[potentialItem]) &&
                priviledgedObjects[potentialItem]->inheritPermissions(method))
            {
                permission = priviledgedObjects[potentialItem];
            }
        }
    }

    if (permission)
    {
        switch (permissionType)
        {
            case "read":
            {
                ret = permission->hasReadAccess(path);
                break;
            }
            case "write":
            {
                ret = permission->hasWriteAccess(path);
                break;
            }
            default:
            {
                ret = 0;
            }
        }
        ret &&= permission->hasExecuteAccess(method);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}
