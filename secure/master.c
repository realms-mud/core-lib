//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/obj/security.h"
#include "master.h"
#include "/secure/wizlist.h"
#include "/sys/driver_hook.h"
#include "/sys/interactive_info.h"

virtual inherit "/secure/master/command-parser.c";
virtual inherit "/secure/master/connect.c";
virtual inherit "/secure/master/hooks.c";
virtual inherit "/secure/master/logging.c";
virtual inherit "/secure/master/preload.c";
virtual inherit "/secure/master/security.c";
virtual inherit "/secure/master/user-management.c";


/////////////////////////////////////////////////////////////////////////////
public nomask void inaugurate_master(int arg)
{
    addDriverHooks();
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed get_master_uid()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int query_prevent_shadow()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string get_simul_efun()
{
    string simulEfunName = "/secure/simul_efun.c";
    object simulEfun;
    
    string failure = catch(
        simulEfun = load_object(simulEfunName)
    );

    if (failure)
    {
        printf("Failed to load simul_efun: %O\n", failure);
        shutdown();
        simulEfunName = 0;
    }
    else
    {
        simulEfun->start_simul_efun();
    }

    return simulEfunName;
}

// Here's the junk that has not yet been cleaned up / fixed for the new lib


/////////////////////////////////////////////////////////////////////////////
public nomask void destruct_environment_of(object ob)
{
    if (!ob || !interactive(ob))
        return;
    tell_object(ob, "Everything you see is disolved. Luckily, you are "
        "transported somewhere...\n");
    ob->move_player("abruptly#room/void");
}

void runtime_error(string error, string program, string current_object, int line)
{
//    "secure/dblog"->log_error(current_object, program, line, error);
    if (this_player() && interactive(this_player()))
        catch (write((member(inherit_list(this_player()),
            "lib/realizations/wizard.c") > -1) ?
            //        query_player_level("error messages") ?
            current_object ?
            error +
            "program: " + program +
            ", object: " + current_object +
            " line " + line + "\n"
            :
            error
            :
            "Your sensitive mind notices a wrongness in the fabric of space.\n"
        ));
}

/* An error in this function can be very nasty. Note that unlimited recursion
 * is likely to cause errors when environments are deeply nested
 */

int move_interactive_ob(object ob)
{
#if ! __EFUN_DEFINED__(query_ip_name)
    if (interactive(ob) && efun::interactive_info(ob, II_IP_NUMBER))
#else
    if (query_ip_number(ob))
#endif
    {
        object env;
        env = environment(ob);
        move_object(ob, find_object("secure/master"));
        if (env == environment(ob))
            destruct(ob);
        return 1;
    }
    return 0;
}

void move_or_destruct(object what, object to)
{
    mixed temp;

    catch (temp = what->drop());
    if (temp)
    {
        if (what)
            destruct(what);
        return;
    }

    temp = 0;
    catch (temp = what->short(3));
    if (!stringp(temp))
    {
        if (what)
            destruct(what);
        return;
    }
    if (!catch (move_object(what, to)) && environment(what) == to)
        return;
    /*
     * Failed to move the object. Then, it is destroyed.
     */
    if (!move_interactive_ob(what))
        destruct(what);
}

mixed prepare_destruct(object ob)
{
    object env, *all;
    mixed *errors;
    int i;

#if 6 * 7 != 42 || 6 * 9 == 42
    return "Preprocessor error";
#endif

    /*
    #ifdef COMPAT_FLAG
        errors = prepare_destruct1(ob);
        for(i = sizeof(errors); i--; ) {
            write(errors[i]);
        }
    #endif  COMPAT_FLAG */
    env = environment(ob);
    all = all_inventory(ob);
    while (sizeof(all))
    {
        if (env)
        {
            for (i = 0; i < sizeof(all); i++)
                move_or_destruct(all[i], env);
        }
        else
        {
            for (i = 0; i < sizeof(all); i++)
                if (!move_interactive_ob(all[i]))
                {
                    destruct(all[i]);
                }
        }
        all = all_inventory(ob);
    }
    // Don't do this.  Bad things can happen if a wizard decides
    // to destruct ob inside the notify_destruct function.
    // - Maelik
    //catch(ob->notify_destruct());
    return 0; /* success */
}

/* intermud stuff */
void receive_imp(string sender, string packet)
{
    //"players/james/intermud-0.7/inetd"->receive_udp(sender, packet);
    "/secure/intermud/inetd"->receive_udp(sender, packet);
}

int heart_beat_error(object culprit, string err, string program,
    string curobj, int line)
{
    write_file("/log/HEARTBEAT", sprintf(
        "%s: %s, %s, %d, %s\n%O\n",
        ctime(time()), program, curobj, line, err, culprit));

    if (program == "obj/player.c" || (culprit && interactive(culprit)))
        return 1; // its a player, let it continue
    else
        if (culprit && culprit->query_npc())
            destruct(culprit); // It's a creature and it bugged, dest it, in case
                               // people continue to try and attack it for free
                               // xp.
    return 0; // Stop the heart beat in this object
}

int query_allow_command(object obj1, object obj2)
{
    int l1, l2;

    /* Yes, you may force yourself to do things ... */
#if 0
    write("secure/master: query_allow_command ");
    if (obj1) write(object_name(obj1));
    else write("0");
    write(" ");
    if (obj2) write(object_name(obj2));
    else write("0");
    write("\n");
#endif

    if (obj1 == obj2) return 1;
    if (!obj1 || !obj2) return 0;

    l1 = (int)obj1->query_level();
    l2 = (int)obj2->query_level();

    /* A monster is never allowed to force a wiz, no matter what monster-level */
    if ((!interactive(obj1) && l2 > 30) ||
        (l1 < l2 && l2 > 30))
    {
        if (!interactive(obj1)) log_error("COMMAND", object_name(obj1) + " ");
        log_error("COMMAND", obj1->query_name() + " (" + obj1->query_real_name() +
            "), creator: " + creator(obj1) + " failed to command() " +
            obj2->query_real_name() + " at " + ctime(time()) + "\n");
        return 0;
    }
    return 1;
}
