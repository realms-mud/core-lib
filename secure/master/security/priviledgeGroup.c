//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected nosave int Unknown = 0x8;
protected nosave int None = 0x0;
protected nosave int Owner = 0x1;
protected nosave int Write = 0x2;
protected nosave int Read = 0x4;

private string Name;
private mapping Permissions = ([
]);

private string *commands = ({ });
private int canInheritPermissions = 0;

/////////////////////////////////////////////////////////////////////////////
protected void applyGroupDetails()
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        applyGroupDetails();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string sanitizePath(string path)
{
    string *traversePath = explode(path, "/") - ({ "." }) - ({ "" });

    int depth = sizeof(traversePath);
    if (depth > 0)
    {
        int i = 1;
        // First pass, strip out any ".." except for the leading one.
        // It's OK if this results in "/../../../blah"
        while((i != depth) && (depth > 0) && (i >= 0))
        {
            if (traversePath[i] == "..")
            {
                traversePath[i-1 ..i] = ({ });
                i--;
                depth = sizeof(traversePath);
            }
            else
            {
                i++;
            }
        }
        traversePath -= ({ ".." });
    }

    return "/" + implode(traversePath, "/");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int hasPermissions(string path, mapping root)
{
    return member(root, path) && member(root[path], "permissions");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getPermissionForPath(string path, mapping root)
{
    int permissionFlags = Unknown;
    string *traversePath = explode(path, "/") - ({ "" });

    if ((sizeof(traversePath) == 1) && hasPermissions(traversePath[0], root))
    {
        permissionFlags = root[traversePath[0]]["permissions"];
    }
    else if ((sizeof(traversePath) > 1) && 
        (member(root, traversePath[0]) || member(root, "$ANY")))
    {
        string pathSegment = member(root, traversePath[0]) ? 
            traversePath[0] : "$ANY";

        permissionFlags = getPermissionForPath(
            implode(traversePath[1..], "/"), root[pathSegment]);
    }
    if ((permissionFlags == Unknown) && member(root, "permissions"))
    {
        permissionFlags = root["permissions"];
    }

    return permissionFlags;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string hasReadAccess(string path)
{
    string ret = 0;

    if (getPermissionForPath(path, Permissions) & Read)
    {
        ret = path;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string hasWriteAccess(string path)
{
    string ret = 0;
    if (getPermissionForPath(path, Permissions) & Write)
    {
        ret = path;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasExecuteAccess(string command)
{
    return (member(commands, command) > -1);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setName(string name)
{
    Name = name;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void createPermissionForPath(int permission, string path, mapping root)
{
    string *traversePath = explode(path, "/") - ({ "" });

    if (!sizeof(traversePath))
    {
        root["permissions"] = permission;
    }
    else if (sizeof(traversePath) == 1)
    {
        if (!member(root, traversePath[0]))
        {
            root[traversePath[0]] = ([ ]);
        }
        root[traversePath[0]]["permissions"] = permission;
    }
    else if (sizeof(traversePath) > 1)
    {
        if (!member(root, traversePath[0]))
        {
            root[traversePath[0]] = ([]);
        }

        createPermissionForPath(permission,
            implode(traversePath[1..], "/"),
            root[traversePath[0]]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addPermission(string path, int permission)
{
    if (!sizeof(path) || (sizeof(path) && (path[0] != '/')))
    {
        raise_error("priviledgeGroup: The supplied path must be an absolute path.\n");
    }

    createPermissionForPath(permission, sanitizePath(path), Permissions);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addPriviledgedEfun(string command)
{
    if ((member(({ "exec", "trace", "set_this_player", "set_this_object",
        "save_object", "copy_file", "write_file", "mkdir", "rmdir",
        "write_bytes", "remove_file", "rename_from", "rename_to",
        "file_size", "get_dir", "read_file", "read_bytes",
        "restore_object", "print_file", "memdump", "objdump",
        "opcdump", "garbage_collection" }), command) > -1))
    {
        commands = m_indices(mkmapping(commands + ({ command })));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void allowInheritedPermissions()
{
    canInheritPermissions = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int inheritPermissions(string method)
{
    return canInheritPermissions && (member(commands, method) > -1);
}
