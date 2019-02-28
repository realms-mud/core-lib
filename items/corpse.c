//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/container.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "name":
        {
            ret = "corpse";
            break;
        }
        case "type":
        {
            ret = "corpse";
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a large object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a corpse";
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void decayCorpse()
{
    remove_call_out("decayCorpse");

    string shortDescription = "";
    int decayValue = query("decay value");
    string corpseName = query("corpse");

    if (corpseName)
    {
        corpseName = capitalize(corpseName);

        switch (decayValue)
        {
            case 8..10:
            {
                shortDescription = sprintf("The corpse of %s", corpseName);
                break;
            }
            case 6..7:
            {
                shortDescription = sprintf("A flock of buzzards circle overhead, eyeing the "
                    "corpse of %s hungrily...", corpseName);
                break;
            }
            case 4..5:
            {
                shortDescription = sprintf("Buzzards walk around the corpse of %s, picking at "
                    "it's flesh.", corpseName);
                break;
            }
            case 2..3:
            {
                shortDescription = sprintf("Several buzzards pull at the intestines of the "
                    "corpse of %s.", corpseName);
                break;
            }
            default:
            {
                shortDescription = sprintf("Buzzards fly away from the skeletonized remains of %s.",
                    corpseName);
                break;
            }
        }
    }
    if ((decayValue >= 0) && corpseName)
    {
        if ((query("short") != shortDescription) && environment(this_object()))
        {
            tell_room(environment(this_object()), shortDescription + "\n");
        }

        set("short", shortDescription);
        if (decayValue - 1)
        {
            set("decay value", decayValue - 1);
        }
        else
        {
            unset("decay value");
        }

        call_out("decayCorpse", 30 + random(15));
    }
    else if(environment(this_object()))
    {
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void corpseSetup(object victim)
{
    string *cleanUpMessage = ({
        "The corpse turns to dust and is blown away by a breeze.\n",
        "A huge mass of maggots erupt from the corpse, consuming it.\n",
        "A pack of rats appears out of nowhere, carrying the corpse away.\n",
        "The corpse sinks into the ground, swallowed up by the earth.\n",
        "A small man walks by, pushing a wheelbarrow in front of him.\n"
        "The old man says, 'Are you planning on using this? Didn't think so.'\n"
        "The man throws the corpse in the wheelbarrow, licks his lips\n"
        "in anticipation, and pushes the wheelbarrow away...\n",
    });

    set("clean up message", cleanUpMessage[random(5)]);
    set("decay value", 10);
    set("short", sprintf("The corpse of %s", capitalize(victim->RealName())));
    set("corpse", victim->RealName());
    set("aliases", ({ victim->RealName(), query("short"), "corpse" }));

    int weight = victim->transferItemsTo(this_object());
    set("weight", weight + 5);
    
    object money = victim->transferMoneyFrom();
    if (money)
    {
        move_object(money, this_object());
    }

    call_out("decayCorpse", 30 + random(15));
}
