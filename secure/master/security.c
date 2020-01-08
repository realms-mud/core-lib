//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

static int source(object ob, string file)
{
    int tmp;
    if (!objectp(ob)) return 0;
    return sscanf(object_name(ob), file + "#%d", tmp);
}

int valid_snoop(object snooper, object snoopee)
{
    if (source(previous_object(), "godstf/s"))
        return 1;
    else
        return interactive(previous_object());
}

int valid_query_snoop(object wiz)
{
    if (source(previous_object(), "godstf/s") ||
        previous_object() == this_object())
        return 1;
    else
        return interactive(previous_object());
}

/*
 * The master object is asked if it is ok to shadow object ob. Use
 * previous_object() to find out who is asking.
 *
 * In this example, we allow shadowing as long as the victim object
 * hasn't denied it with a query_prevent_shadow() returning 1.
 */
int query_allow_shadow(object ob)
{
    if (function_exists("valid_read", previous_object()) ||
        function_exists("valid_write", previous_object()) ||
        function_exists("users", previous_object()))
        return 0;
    return !ob->query_prevent_shadow(previous_object());
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
 
void w_log(string str) {        
        write_file("/godstf/secure_writes",str);
        return;
}
 
void pl_log(string str) {        
        write_file("/godstf/player_writes",str);
        return;
}
 
void misc_log(string str) {        
        write_file("/godstf/misc_writes",str);
        return;
}

void gu_log(string str) {
  write_file("/godstf/guild_writes", str);
  return;
}

mixed valid_write(mixed path, string eff_user, string call_fun, object caller)
{
    string user,file,intern;
    object inter;
 
  if(this_interactive()) {
     inter=this_interactive();
     intern=inter->query_real_name();
  }
 
 if(inter && inter->query_debug() && intern && caller && path && call_fun)
   tell_object(inter, "master_valid_write->path: "+to_string(path)+
               " call_func: "+call_fun+" caller: "+object_name(caller)+
               " interactive: "+intern+"\n");
 
 if(inter && path && call_fun && call_fun != "save_object"
    && call_fun != "write_file" && intern && 
    intern != "someone trying to log on") {
        string pathh, whoo, whooo;
        pathh=inter->query_path();
        path=to_string(path);
    if(sscanf(path,"/secure/%s",whoo) == 1 || 
       sscanf(path,"secure/%s",whoo) == 1) {
               w_log(sprintf("WRITE->path: %s call_func: %s "+
               "name: %s caller: %s on %s\n", path, call_fun, 
               intern, object_name(inter), ctime(time())));
    } else if(sscanf(path, "/guild/%s", whoo) == 1 ||
              sscanf(path, "guild/%s", whoo) == 1) {
               gu_log(sprintf("WRITE->path: %s call_func: %s "+
               "name: %s caller: %s on %s\n", path, call_fun, 
               intern, object_name(inter), ctime(time())));
    } else if((sscanf(path,"/players/%s/%s",whoo,whooo) == 2 || 
               sscanf(path,"players/%s/%s",whoo,whooo) == 2) && 
               whoo != intern) {
               pl_log(sprintf("WRITE->path: %s call_func: %s "+
               "name: %s caller: %s on %s\n", path, call_fun, 
               intern, object_name(inter), ctime(time())));
    }
 }
 
    switch ( call_fun ) {
        case "save_object":
            path = explode(path,"/")-({"","."});
            if (member(path, "..")>=0)
                return 0;
            file = object_name(previous_object());
            if ( stringp(user = creator_file(file)) ) {
                if (user[0]>='A' && user[0]<='Z')
                {
                    if (sizeof(path)>=3 && path[0]=="domains" &&
                        path[1]==lower_case(user))
                        return implode(path,"/");
                }
                else
                {
                    if (sizeof(path)>=3 && path[0]=="players" &&
                        path[1]==user)
                        return implode(path,"/");
                } 
        } else
                {
          if ((sizeof(path)>=2 && (path[0]=="p" || path[0]=="secure")) 
                && !(source(previous_object(),"obj/player") 
                || source(previous_object(), "lib/realizations/player")
                || source(previous_object(), "secure/player/player")
                || source(previous_object(), "secure/login")
                || source(previous_object(), "secure/simul_efun")
                || source(previous_object(), "secure/ipbanish")
                || source(previous_object(), "secure/player/harbplayer")
                || source(previous_object(), "secure/master")))
                   return 0;
                if (file[0..3] == "obj/"  ||
                    file[0..4] == "room/" ||
                    file[0..3] == "std/" || file[0..6] == "secure/" || 
                    file[0..5] == "guild/")
                        return implode(path,"/");
                if ((file[0..6] == "nobles/") && sizeof(path) >= 2 &&
                    path[0] == "nobles" && path[1] == "data")
                        return implode(path, "/");
        }
        default:
            return 0; /* deny access */
        case "copy_file":
        case "write_file":
            if (path[0..2]=="/p/" &&
            !(source(previous_object(),"obj/player")  || 
            source(previous_object(), "secure/player/player") 
            || source(previous_object(), "lib/realizations/player")
            || source(previous_object(), "secure/login")
            || source(previous_object(), "secure/simul_efun")
            || previous_object()->query_level() < 10050))
                return 0;
            if(path[0..4] == "/log/" &&
              member(path[5..],'/') < 0 &&
              path[5] != '.' &&
              sizeof(path) <= 35
            ) {
                return path;
            }
            if (caller == this_object()) return 1;
            break;
        case "ed_start":
            if (path[0]!='/') path = "/"+path;  /* 930115 Herp */
            break;
        case "mkdir":
            file = object_name(previous_object());
            if ( file[0..10] == "nobles/obj/" && path[0..11] == "nobles/data/")
                return path;
	 if(file == "secure/master")     
         return path;
            break;
        case "rmdir":
        case "write_bytes":
        case "remove_file":
            if (caller == this_object()) return 1;
        case "cindent":
            break;
        case "rename_from":
        case "rename_to":
        case "do_rename": /* foslay 7-19-92 */
            if (object_name(caller)=="secure/simul_efun")
                return path;
            break;
    }
    set_this_object(caller);
#if ! __EFUN_DEFINED__(query_ip_name)
    if( this_player() && efun::interactive_info(this_player(), II_IP_NUMBER)) {
#else
    if( this_player() && query_ip_number(this_player()) ) {
#endif
    if(!this_player()->hasWriteAccess(path))
    {
        path = 0;
    }

//        path = (string)this_player()->valid_write(path);
        if (!stringp(path)) {
            write("Bad file name (master::valid_write): "+path+" "+call_fun+".\n");
            return 0;
        }
        return path;
    }
//    path = ({string})"obj/player"->valid_write(path);
    if(this_player() && !this_player()->hasWriteAccess(path))
    {
        path = 0;
    }

    if (stringp(path))
        return path;
    /* else return 0, denying access */
}
 
mixed valid_read(string path, string eff_user, string call_fun, object caller) {
  string user, x, y;
  object temp;

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
        case "file_size":
           temp = previous_object();
           if(temp && (source(temp,"obj/player") || source(temp,"secure/player/player") || sizeof(regexp(({ object_name(caller) }), "^lib/"))))
             return 1;

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
                source(this_player(),"lib/realizations/wizard")) {
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
 