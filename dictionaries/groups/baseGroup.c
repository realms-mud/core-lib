//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public nomask string group()
{
    string group = 0;

    string *groupName = regexp(({ program_name(this_object()) }),
        "^lib/.*dictionaries/groups/[a-zA-Z]+\.c$");
    if (sizeof(groupName))
    {
        group = regreplace(groupName[0],
            "^lib/.*dictionaries/groups/([a-zA-Z]+)\.c$",
            "\\1");
    }
    return group;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isMemberOf(object user)
{
    object *members = filter_array(users(),
        (: return (program_name($1) == "lib/realizations/wizard.c") &&
            (member($1->groups(), group()) > -1); :));

    return user && objectp(user) && sizeof(members) &&
        (member(members, user) > -1);
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
private nomask varargs string convertRelativePathToAbsolutePath(object user, string path, int doNotConvert)
{
    string ret = path;

    if (user && objectp(user))
    {
        if(sizeof(ret) && (ret[0] != '/') && user->workingDirectory())
        {
            ret = user->workingDirectory() + ret;
        }

        if ((user->Name() != "") && !doNotConvert)
        {
            ret = regreplace(ret, lower_case(user->Name()), "$USER");
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasReadAccess(object user, string path)
{
    return isMemberOf(user) && getPermissionForPath(
        sanitizePath(convertRelativePathToAbsolutePath(user, path)),
        Permissions) & Read;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getFullyQualifiedPath(object user, string path)
{
    return sanitizePath(convertRelativePathToAbsolutePath(user, path, 1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasWriteAccess(object user, string path)
{
    return isMemberOf(user) && getPermissionForPath(
        sanitizePath(convertRelativePathToAbsolutePath(user, path)),
        Permissions) & Write;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasOwnershipAccess(object user, string path)
{
    return isMemberOf(user) && getPermissionForPath(
        sanitizePath(convertRelativePathToAbsolutePath(user, path)),
        Permissions) & Owner;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasExecuteAccess(object user, string command)
{
    return isMemberOf(user) && (member(commands, command) > -1);
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
        raise_error("baseGroup: The supplied path must be an absolute path.\n");
    }

    createPermissionForPath(permission, sanitizePath(path), Permissions);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addCommand(string command)
{
    if ((member(get_dir("/lib/commands/wizard/"), command + ".c") > -1))
    {
        commands = m_indices(mkmapping(commands + ({ command })));
    }
}