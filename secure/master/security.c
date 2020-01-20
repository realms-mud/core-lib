//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

private object priviledgedObjects = 
    load_object("/secure/master/security/priviledgedObjects.c");
private mapping accessCache = ([]);

/////////////////////////////////////////////////////////////////////////////
private int isPriviledgedObject(mixed caller)
{
    int ret = 0;

    string name = 0;
    if (objectp(caller))
    {
        name = object_name(caller);
    }
    else if (stringp(caller))
    {
        name = caller;
    }

    if (sizeof(regexp(({ name }), "^(lib/modules/secure|secure)")))
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int valid_snoop(object snooper, object snoopee)
{
    return isPriviledgedObject(previous_object()) ||
        (interactive(previous_object() &&
            previous_object()->hasExecuteAccess("snoop")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int valid_query_snoop(object caller)
{
    return isPriviledgedObject(previous_object()) || 
        (interactive(previous_object() && 
            previous_object()->hasExecuteAccess("query-snoop")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int query_allow_shadow(object caller)
{
    int ret = !caller->preventShadows();

    if (isPriviledgedObject(caller))
    {
        ret = 0;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int valid_exec(string caller, object newObject, object oldObject)
{
    object callingObject = load_object(caller);
    return objectp(callingObject) && isPriviledgedObject(callingObject);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int valid_trace(string name)
{
    return this_player() && interactive(this_player()) &&
        interactive_info(this_player(), II_IP_NUMBER) &&
        (member(inherit_list(this_player()), "lib/realizations/wizard.c") > -1) &&
        (member(this_player()->groups(), "archwizard") > -1);
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
        while ((i != depth) && (depth > 0) && (i >= 0))
        {
            if (traversePath[i] == "..")
            {
                traversePath[i - 1 ..i] = ({ });
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
private nomask int userHasWriteAccess(string path)
{
    return this_player() && interactive(this_player()) &&
        interactive_info(this_player(), II_IP_NUMBER) &&
        this_player()->hasWriteAccess(path);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int userHasReadAccess(string path)
{
    return this_player() && interactive(this_player()) &&
        interactive_info(this_player(), II_IP_NUMBER) &&
        this_player()->hasReadAccess(path);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isCachedValue(string path, string method, object caller,
    string type)
{
    return member(accessCache, sprintf("%O%O%O%O", type, path, method, caller));
}

/////////////////////////////////////////////////////////////////////////////
static nomask void pruneAccessCache()
{
    int pruneTime = time() - 60;

    string *keysToRemove = filter(m_indices(accessCache),
        (: $2[$1] < $3 :), accessCache, pruneTime);

    foreach(string key in keysToRemove)
    {
        m_delete(accessCache, key);
    }
    call_out("pruneAccessCache", 60);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string valid_write(string path, string uid, string method, 
    object caller)
{
    string sanitizedPath = 0;

    if (isCachedValue(path, method, caller, "write") ||
        isPriviledgedObject(caller) ||
        userHasWriteAccess(path) ||
        priviledgedObjects->hasPermission(path, method, caller, "write"))
    {
        sanitizedPath = sanitizePath(path);
        accessCache[sprintf("%O%O%O%O", "write", path, method, caller)] = 
            time();
    }

    if (!stringp(sanitizedPath))
    {

        printf("Bad file name (master::valid_write): %O (%O), caller %O\n",
            path, method, caller);
    }
    return sanitizedPath;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string valid_read(string path, string uid, string method,
    object caller)
{
    string sanitizedPath = 0;

    if (isCachedValue(path, method, caller, "read") ||
        isPriviledgedObject(caller) ||
        userHasReadAccess(path) ||
        priviledgedObjects->hasPermission(path, method, caller, "read"))
    {
        sanitizedPath = sanitizePath(path);
        accessCache[sprintf("%O%O%O%O", "read", path, method, caller)] =
            time();
    }

    if (!stringp(sanitizedPath))
    {
        printf("Bad file name (master::valid_read): %O (%O), caller %O\n",
            path, method, caller);
    }

    return sanitizedPath;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int privilege_violation(string what, mixed who, mixed where, 
    mixed argument)
{
    int ret = isPriviledgedObject(who) ? 1 : -1;

    switch(what) 
    {
        case "call_out_info":
        case "mysql": 
        {
            ret = 1;
            break;
        }
        case "nomask simul_efun":
        {
            ret = (who == "secure/simul_efun.c");
            break;
        }
        case "input_to":
        {
            ret = (strstr(object_name(who), "secure/login#") == 0) ? 1 : -1;
            break;
        }
    }
    return ret;
}
