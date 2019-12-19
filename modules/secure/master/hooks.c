//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
static string _include_dirs_hook(string include_name, string current_file)
{

}

/////////////////////////////////////////////////////////////////////////////
static void _move_hook_fun(object item, object dest)
{

}

/////////////////////////////////////////////////////////////////////////////
static mixed _load_uids_fun(mixed object_name, object prev)
{

}

/////////////////////////////////////////////////////////////////////////////
static mixed _clone_uids_fun(object blueprint, string new_name, object prev)
{

}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addDriverHooks()
{
/*  set_driver_hook(
        H_MOVE_OBJECT0,
        unbound_lambda( ({'item, 'dest}),
        ({#'_move_hook_fun, 'item, 'dest })
                      )
                 );
  set_driver_hook(
    H_LOAD_UIDS,
    unbound_lambda( ({'object_name}), ({
      #'_load_uids_fun, 'object_name, ({#'previous_object}) })
                  )
  );
  set_driver_hook(
    H_CLONE_UIDS,
    unbound_lambda( ({ 'blueprint, 'new_name}), ({
      #'_clone_uids_fun, 'blueprint, 'new_name, ({#'previous_object}) })
                  )
  );
  set_driver_hook(H_CREATE_SUPER, "reset");
  set_driver_hook(H_CREATE_OB,    "reset");
  set_driver_hook(H_CREATE_CLONE, "reset");

  set_driver_hook(H_RESET,        "reset");
  set_driver_hook(H_CLEAN_UP,     "clean_up");
  set_driver_hook(H_MODIFY_COMMAND,
    ([ "e":"east", "w":"west", "s":"south", "n":"north"
     , "d":"down", "u":"up", "nw":"northwest", "ne":"northeast"
     , "sw":"southwest", "se":"southeast" ]));
  set_driver_hook(H_MODIFY_COMMAND_FNAME, "modify_command");
  set_driver_hook(H_NOTIFY_FAIL, "What?\n");
//set_driver_hook(H_INCLUDE_DIRS, INCLUDE_DIRS_LIST);
  set_driver_hook(H_INCLUDE_DIRS, 
    unbound_lambda( ({'included, 'file}),
      ({#'_include_dirs_hook,'included,'file }) ));

#if ! __EFUN_DEFINED__(query_ip_name)
  set_driver_hook(H_AUTO_INCLUDE,
#else
  set_auto_include_string(
#endif
    "#pragma combine_strings\n"
    "#pragma local_scopes\n" // Required for local variable scopes - Kilan
//  "#pragma strict_types\n" // To stop untyped crappy code - Kilan
// WAY too much crappy code to turn strict types on.
  );
  */
}
