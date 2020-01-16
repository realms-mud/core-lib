//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

// TODO [675]: Rewrite this horrendous code... it doesn't actually work anyway.

int verify_create_wizard(object ob)
{
    return (ob && file_size("players/" + ob->query_real_name()) == -2 &&
        ob->query_is_wiz() >= 5000);
}

status suicide(string victim, object me) {
  if(!previous_object() || !interactive(previous_object())) return(0);
  if(me != previous_object()) return(0);
  if(me->query_real_name() == "guest") return(0);
  if(me->query_is_wiz()) return(0); // RM NO wizards, period.
    
  write("You pull out a LARGE knife and slam it into your brain, ciao.\n");
  say(capitalize(victim)+" pulls out a LARGE knife, and slams it into "+
  "its brain.\n");
/*  possessive(me)+" brain.\n"); */
  call_out("rm_player",2,victim);
  me->new_shout("A HUGE roar goes up from the crowd as "
  +capitalize(victim)+" slams a knife into its brain.\n");
/*  +capitalize(victim)+" slams a knife into "+possessive(me)+" brain.\n"); */
#if ! __EFUN_DEFINED__(query_ip_name)
    mixed ipAddr = efun::interactive_info(me, II_IP_NUMBER);
#else
    mixed ipAddr = query_ip_number(me);
#endif

 "secure/simul_efun"->log_file("SUICIDE",to_string(ipAddr)+" suicided on "+
     ctime(time())+". Name of "+victim+"\n");
  command("quit",me);
  return(1);
}
 
static void rm_player(string name)
{
//#define PRINT(a) tell_object(find_player("bofin"),sprintf("%O %O:%O",__FILE__,__LINE__,a))
  string vic;
  int handle;

  handle="/godstf/usertables"->db_connect();
  remove_call_out("rm_player");
//PRINT(handle);
  if (handle)
  {
    int anotherhandle;
    int dellogin;
    string victim;
    mixed res;
// is this a character or a login name    
    db_exec(handle,sprintf("select id from users where login='%s'",
      db_conv_string(name)));
    res=db_fetch(handle);
//PRINT(res);
    if (!res) // not a login, just the character
      res=({name});
    else
    {
      while (db_fetch(handle));
      dellogin=1;
      db_exec(handle,sprintf("select player from chars where id='%s'",
        db_conv_string(res[0])));
      res=db_fetch(handle);
//PRINT(res);
    }
//PRINT(res);
    while (res)
    {
//PRINT(res);
      victim=res[0];
      victim=db_conv_string(victim);
      vic=victim[0..0]+"/"+victim+".o";
      ("/players/animal/houses/master_house")->remove_house(victim);
      rm("/players/animal/alias/"+vic);
      rm("/players/animal/houses/"+victim+".o");

      rm("/secure/passwd/"+victim);
      rm("/p/"+vic);
      rm("/room/post_dir/"+victim+".o");
      rm("/mail/"+vic);  // Bofin 2/7/01

      rm("/guild/monster/monsters/"+victim+".o");
      rm("/guild/priest/priests/"+victim+".o");
      rm("/guild/thief/members/"+victim+".o");
      rm("/guild/mage/members/"+victim+".o");
      rm("/guild/bard/members/"+victim+".o");
      rm("/guild/druid/druids/"+victim+".o");
      rm("/guild/druid/groves/"+victim+".o");
      rm("/guild/fighter/members/"+victim+".o");
      rm("/guild/knight/knights/"+victim+".o");
      rm("/guild/necromancer/members/"+victim+".o");
      
      rm("/players/kilan/closed/headshop/pks/"+victim+".o");
      rm("/players/gor/militia/recruits/"+vic);
      rm("/players/maelik/fortress/fortresses/"+victim+".o");
      rm("/players/maelik/fortress/data/"+victim+".o");
      rm("/players/tigerfolly/hall/obj/journals/"+victim+".o");
      rm("/players/kilan/waypoints/data/"+vic);
      rm("/players/kilan/friend/friendlist/"+vic);
      rm("/players/grant/skins/data/"+victim+".o");

      anotherhandle="/godstf/usertables"->db_connect();
      db_exec(anotherhandle,"delete from channel_settings "
                     "where player='"+victim+"'");
      db_exec(anotherhandle,"delete from chars "
                     "where player='"+victim+"'");
      db_close(anotherhandle);
      res=db_fetch(handle);
    }
    
    while (res=db_fetch(handle));
    if (dellogin)
    {
      db_exec(handle,"delete from users where login='"+name+"'");
    }
    db_close(handle);
  }
}

/*
 * Create a home dritectory and a castle for a new wizard. It is called
 * automatically from create_wizard(). We don't use the 'domain' info.
 * The create_wizard() efun is not really needed any longer, as a call
 * could be done to this function directly.
 *
 * This function can create directories and files in /players. It is
 * garded from calls from the wrong places.
 */
string master_create_wizard(string owner, string sponsor, object caller) {
    string *def_dirs = ({"bin","closed",".dead_ed_files"});

    string def_castle,def_workroom;
    string dest, castle, workroom, wizard;
    object player;
 
    player = funcall(symbol_function('find_player),owner);
 
    if (!player)
        return 0;
    if (!verify_create_wizard(caller)) {
        tell_object(player, "That is an illegal attempt!\n");
        return 0;
    }
    if (caller != previous_object() && 
        object_name(previous_object())!="secure/player/bin/wizard/_make_wizard")
    {
      
      tell_object(player, "Faked call!\n");
      return 0;
    }
    wizard   = "/players/" + owner;
    castle   = "/players/" + owner + "/castle.c";
    workroom = "/players/" + owner + "/workroom.c";
 
    if (file_size(wizard) == -1) {
        tell_object(player, "You now have a home directory: " +
                    wizard + "\n");
        mkdir(wizard);
    }
    dest = object_name(environment(player));
 
    /* 920414 Herp: create the workroom first */
 
    def_workroom = "#define NAME \"" + owner + "\"\n\n" +
        read_file("/room/def_workroom.c");
    if (file_size(workroom) > 0) {
       tell_object(player, "You already have a workroom !\n");
    } else {
        /* The master object can do this ! */
        if (write_file(workroom, def_workroom))
           tell_object(player, "You now have a workroom: "+workroom+"\n");
        else
           tell_object(player, "Failed to create your workroom!\n");
    }
 
    def_castle = "#define NAME \"" + owner + "\"\n#define DEST \"" +
        dest + "\"\n" + read_file("/room/def_castle.c");
    if (file_size(castle) > 0) {
        tell_object(player, "You already had a castle !\n");
    } else {
        /* The master object can do this ! */
        if (write_file(castle, def_castle)) {
            tell_object(player, "You now have a castle: " + castle + "\n");
            if (!write_file("/room/init_file", castle[1..]  + "\n"))
                tell_object(player, "It couldn't be loaded automatically!\n");
        } else {
            tell_object(player, "Failed to make castle for you!\n");
        }
    }
    map(def_dirs,lambda(({'dir,'pre}),
      ({#'mkdir,({#'sprintf,"%s/%s",'pre,'dir}) })), "/players/" + owner);
    mkdir("open/" + owner);
    
//  "/secure/passwd/logs/list"->add(owner);

    player->set_level(101);
    player->save_me(0);
    return castle;
}
