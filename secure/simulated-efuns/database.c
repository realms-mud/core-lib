//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private int hasBeenValidated = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask int DatabaseVersion()
{
    return 5;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string RealmsDatabase()
{
    return "RealmsLib";
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAccessDatabase(object previous)
{
    string *programsWithPermission = ({ "lib/realizations/player.c",
        "lib/realizations/wizard.c", "lib/commands/player/save.c",
        "lib/commands/player/quit.c", "secure/login.c",
        "lib/modules/secure/login.c", "secure/master/user-management.c",
        "lib/modules/creation/initializePlayer.c",
        "secure/simulated-efuns/database.c" });

    if (member(inherit_list(this_object()),
        "secure/simulated-efuns/testing.c") > -1)
    {
        object restoreCaller = call_direct(this_object(), "restoreCaller");
        if (objectp(restoreCaller))
        {
            programsWithPermission += ({ program_name(restoreCaller) });
        }
        programsWithPermission += 
            ({ "lib/tests/support/services/mockPlayer.c" });
    }
    
    return member(programsWithPermission, program_name(previous)) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidPersistenceObject(object persistence)
{
    return member(({ "lib/realizations/player.c",
       "lib/realizations/wizard.c" }), program_name(persistence)) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int db_exec(int dbHandle, string sqlQuery)
{
    int returnedHandle = dbHandle;
    
    if (stringp(sqlQuery) && 
        (sizeof(regreplace(sqlQuery, " ", "", 1)) > 1))
    {
        dbHandle = efun::db_exec(dbHandle, sqlQuery);
    }

    if (dbHandle && (dbHandle != returnedHandle))
    {
        write_file("/log/DBERROR",
            sprintf("%s:\n%s\n%s\nCall stack:%O\n", ctime(time()),
                db_error(dbHandle), sqlQuery, caller_stack()));
    }
    return returnedHandle;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void executeDatabaseScript(int dbHandle, string script)
{
    string *commands = explode(script, "##");
    db_exec(dbHandle, "use " + db_conv_string(RealmsDatabase()) + ";");

    foreach(string command in commands)
    {
        db_exec(dbHandle, command);

        string error = db_error(dbHandle);
        if (error)
        {
            raise_error(
                sprintf("ERROR dataAccess - While executing: %s\n%s\n",
                    command[0..((sizeof(command) > 78) ? 78 : (sizeof(command) - 1))], error));
        }
    }
    while (db_fetch(dbHandle));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void createDatabase(int dbHandle)
{
    string dbScript =
        read_file("/secure/simulated-efuns/database/initial/dropDBContents.sql") + 
        read_file("/secure/simulated-efuns/database/initial/generateDB.sql");

    db_exec(dbHandle, sprintf("show databases like '%s';", 
        db_conv_string(RealmsDatabase())));

    mixed result = db_fetch(dbHandle);
    if (!result || !result[0])
    {
        raise_error("ERROR dataAccess: The Realms database does not exist.\n"
            "Please create it using the following script from outside the MUD:\n"
            "    '/secure/simulated-efuns/database/installDatabase'\n");
    }

    executeDatabaseScript(dbHandle, dbScript);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void migrateDatabase(int dbHandle, int currentVersion,
    int requiredVersion)
{
    string migrationDir = "/secure/simulated-efuns/database/migrations/";

    string *scripts = sort_array(get_dir(migrationDir + "*.sql"), (: $1 > $2 :));

    foreach(string scriptFile in scripts)
    {
        int version = to_int(regreplace(scriptFile, "([0-9]+)_.*", "\\1", 1));
        if ((version <= requiredVersion) && (version > currentVersion))
        {
            string script = read_file(migrationDir + scriptFile);
            executeDatabaseScript(dbHandle, script);

            db_exec(dbHandle, sprintf(
                "update versionInfo set id=%d where versionType='database';",
                version));

            mixed result = db_fetch(dbHandle);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void validateDatabase(int dbHandle)
{
    string query = "select id from versionInfo "
        "where versionType = 'database' order by id desc limit 1;";

    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result && result[0])
    {
        int currentVersion = to_int(result[0]);
        int requiredVersion = DatabaseVersion();
        if (currentVersion < requiredVersion)
        {
            migrateDatabase(dbHandle, currentVersion, requiredVersion);
        }
    }
    else
    {
        createDatabase(dbHandle);
        migrateDatabase(dbHandle, 1, DatabaseVersion());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping availableRoles()
{
    object roleService = load_object("/lib/modules/secure/dataAccess.c");
    return roleService->availableRoles();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int createRole(string newRole, string type)
{
    object roleService = load_object("/lib/modules/secure/dataAccess.c");
    return roleService->addRole(newRole, type);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string addRoleToPlayer(object character, string newRole)
{
    string ret = 0;

    if (objectp(character))
    {
        object roleService = load_object("/lib/modules/secure/dataAccess.c");
        ret = roleService->addRoleToPlayer(character, newRole);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeRoleFromPlayer(object character, string newRole)
{
    int ret = 0;

    if (objectp(character))
    {
        object roleService = load_object("/lib/modules/secure/dataAccess.c");
        ret = roleService->removeRoleFromPlayer(character, newRole);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int db_connect(string database, string user, 
    string password)
{
    int handle;
    if (user && password)
    {
        handle = efun::db_connect(database, user, password);
    }
    else
    {
        // For this to work, you MUST modify pkg-mysql.c, specifically the
        // mysql_real_connect() call to change the default user/password to
        // that used by your MUD. If you would prefer to be a bit less secure,
        // you can change DBUSER and DBPASS on the line below, uncomment it,
        // and comment out the other call.
        // handle = efun::db_connect(database, DBUSER, DBPASS);
        handle = efun::db_connect(database);
    }

    if (!hasBeenValidated)
    {
        validateDatabase(handle);
    }

    return handle;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int db_close(int handle)
{
    return efun::db_close(handle);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int *db_handles()
{
    // disabled for security reasons
    return ({});
}
