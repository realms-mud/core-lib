//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

private object priviledgedObjects = 
    load_object("/secure/master/security/priviledgedObjects.c");

/////////////////////////////////////////////////////////////////////////////
private int isPriviledgedObject(object caller)
{
    int ret = 0;

    string name = object_name(caller);

    if (sizeof(regexp(({ name }), 
        "^(lib/modules/secure|secure|lib/tests/modules/secure|lib/tests/secure)")))
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
int valid_snoop(object snooper, object snoopee)
{
    return isPriviledgedObject(previous_object()) ||
        (interactive(previous_object() &&
            previous_object()->hasExecuteAccess("snoop")));
}

/////////////////////////////////////////////////////////////////////////////
int valid_query_snoop(object caller)
{
    return isPriviledgedObject(previous_object()) || 
        (interactive(previous_object() && 
            previous_object()->hasExecuteAccess("query-snoop")));
}

/////////////////////////////////////////////////////////////////////////////
int query_allow_shadow(object caller)
{
    int ret = !caller->preventShadows();

    if (isPriviledgedObject(caller))
    {
        ret = 0;
    }

    return ret;
}

mixed creator_file(string object_name)
{
    string *path;
    path = explode(object_name,"/")-({"","."});
    switch (sizeof(path) && path[0])
    {
      case "open":
        return "/nil/";
      case "ftp":
      case "log":
        return 0;
      case "players":
        if (sizeof(path)<3)
          return 0;
        return path[1];
      case "domains":
        if (sizeof(path)<3)
          return 0;
        return capitalize(path[1]);
      default:
        return 1;
    }
    return 0;
}
 
/*
 * Function name:   valid_exec
 * Description:     Checks if a certain 'program' has the right to use exec()
 * Arguments:       name: Name of the 'program' that attempts to use exec()
 *                        Note that this is different from object_name(),
 *                        Programname is what 'function_exists' returns.
 *                  NOTE, the absence of a leading slash in the name.
 * Returns:         True if exec() is allowed.
 */
int
valid_exec(string name)
{
  switch ((explode(name,"/")-({"","."}))[0])
  {
    case "lib":
    case "secure":
      return 1;
    default:
      return 0;
  }
  return 0;
}

/*
 * valid_trace() - much the same as valid_exec() but for usage of the
 * trace() efun. I have set this so that only demi+ can use trace(). This
 * will stop those troublesome newbie wizzes crashing the mud.
 */

int valid_trace(string name)
{
  if (this_player() && interactive(this_player()) &&
      this_player()->query_is_wiz()>=5000)
    return 1;
  return 0;
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
public nomask string valid_write(string path, string uid, string method, 
    object caller)
{
    string sanitizedPath = 0;

    if (isPriviledgedObject(caller) ||
        userHasWriteAccess(path) ||
        priviledgedObjects->hasPermission(path, method, caller, "write"))
    {
        sanitizedPath = sanitizePath(path);
    }

    if (!stringp(sanitizedPath))
    {

        printf("Bad file name (master::valid_write): %O (%O), caller %O\n",
            path, method, caller);
    }
    return sanitizedPath;
}
 
/////////////////////////////////////////////////////////////////////////////
mixed valid_read(string path, string eff_user, string call_fun, object caller) {
  string user, x, y;
  object temp;

  if (isPriviledgedObject(caller))
  {
      return path;
  }

  if(this_player() && interactive(this_player()) && this_player()->query_debug() && caller && call_fun && path)
    tell_object(this_player(),"master_valid_read->path: "+to_string(path)+" call_func: "+call_fun+" caller: "+object_name(caller)+"\n"); 

  if(object_name(caller) == "secure/simul_efun") return 1;
  switch ( call_fun ) { case "restore_object": return 1; case "ed_start":
            if (previous_object() && previous_object() != this_player() ) return 0;
            if (!path) {
                /* request for file with last error */
                mixed *error;
 
                error =
                  get_error_file(({string})this_player()->query_real_name());
                if (!error || error[3]) {
                    write("No error.\n");
                    return 0;
                }
                write(error[0][1..]+" line "+error[1]+": "+error[2]+"\n");
                return error[0];
            }
            path = "/"+path;
        case "file_size": return 1;
           temp = previous_object();
//           if(temp && (source(temp,"obj/player") || source(temp,"secure/player/player") || sizeof(regexp(({ object_name(caller) }), "^lib/"))))
//             return 1;

           if(eff_user && 
             (sizeof(regexp(({ path, object_name(caller) }), eff_user)) == 2))
             return 1;
           if(eff_user && 
             (sizeof(regexp(({ object_name(caller) }), eff_user)) == 1) &&
             (sizeof(regexp(({ path }), "^[/]*lib/")) == 1))
             return 1;
//printf("previous = %O, eff_user = %O, caller = %O, path = %O\n", temp, eff_user, caller, path);
        case "get_dir":
            if (caller == this_object() || 
              sscanf(object_name(caller), "guild/%s_soul%s", x, y) == 2 ||
              sizeof(regexp(({ object_name(caller) }), "^lib/")) ||
              caller == find_object("/secure/player/bin/bin_command"))
             return 1;
        case "read_file":
        case "copy_file":
        case "read_bytes":
          if(caller == this_object()) return 1;
          if(sizeof(regexp(({ object_name(caller) }), "^lib/"))) return 1;
          if (strstr(object_name(caller),"secure/login#")==0) return 1;
          if(object_name(caller)=="secure/intermud/inetd" &&
             strstr(path,"/secure/intermud")==0) 
            return 1;
        case "tail":
        case "print_file":
        case "make_path_absolute": /* internal use, see below */
        case "do_rename": /* foslay 7-19-92 */

            set_this_object(caller);
#if ! __EFUN_DEFINED__(query_ip_name)
    if( this_player() && efun::interactive_info(this_player(), II_IP_NUMBER) &&
#else
    if( this_player() && query_ip_number(this_player()) &&
#endif
        1) {
//                source(this_player(),"lib/realizations/wizard")) {
//              path = ({string})this_player()->valid_read(path);
              path = ({string})this_player()->hasReadAccess(path);
              if (!stringp(path)) {
                write("Bad file name (master::valid_read): "+path+" "+call_fun+".\n");
                return 0; }
              return path;
            }
//          printf("fun: %O caller:%O\n",call_fun,caller);
            if (object_name(caller)=="secure/simul_efun") return 1;
            path = ({string})"obj/player"->alt_valid_read(path);
            if(stringp(path))
                return path;
            return 0;
  }
    /* if a case failed to return a value or the caller function wasn't
     * recognized, we come here.
     * The default returned zero indicates deny of access.
     */
  return 0;
}
 
/* privilege_violation is called when objects try to do illegal things,
 * or files being compiled request a privileged efun.
 *
 * return values: 
 *   1: The caller/file is allowed to use the privilege.
 *   0: The caller was probably misleaded; try to fix the error.
 *  -1: A real privilege violation. Handle it as error.
 */
int privilege_violation(string what, mixed who, mixed where) {

//write_file("/log/privilege",sprintf("%s %O %O %O\n", ctime(time()),what,who,where));  

    switch(what) {
      case "mysql": return 1;
      case "nomask simul_efun":
           if (who == "secure/simul_efun.c") {
            return 1;
        }
        return 0;
      case "wizlist_info":
      case "set_extra_wizinfo":
      case "get_extra_wizinfo":
/*
        if (object_name(who)!="global/wizlist") return -1;
*/
        return 1;
      case "call_out_info": return 1;
      case "input_to":
        if (strstr(object_name(who),"secure/login#")==0) return 1;
        return -1;        
      case "send_imp":
//      return 1;

        if (object_name(who) == "secure/intermud/inetd") return 1;
        return 0;
      default:
        return -1; /* Make this violation an error */
    }
    return 0;
}
 