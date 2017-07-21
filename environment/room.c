//*****************************************************************************
// Class: room
// File Name: room.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateObject.c";
#include <mtypes.h>

protected string currentState;

protected mapping stateMachineData = ([
    "default": ([
        "long": "This is the room's long description.",
        "short": "A room",
        "environment type": "unknown",
        "items": ([ ]),
        "objects": ([ ]),
        "persistent objects": ([ ]),
        "destinations": ([ ]),
        "properties": ([ ])
    ])
]);
protected object *objectList = ({ });
protected mapping persistentObjectList = ([ ]);

protected nomask int isValidState(string state)
{
    // These are required elements for all rooms
    return (member(stateMachineData, state) &&
            mappingp(stateMachineData[state]) &&
            member(stateMachineData[state], "long") &&
            stringp(stateMachineData[state]["long"]) &&
            member(stateMachineData[state], "short") &&
            stringp(stateMachineData[state]["short"]));
}

public nomask string *exits()
{
    string *ret = 0;
    if(currentState && member(stateMachineData, currentState))
    {
        ret += m_indices(stateMachineData[currentState]["destinations"]) + 
            ({ });
    }
    return ret;
}

protected nomask void addExits(string state)
{
    // WARNING: This will remove all actions (intended behavior) - If you
    // maintain other actions in the room, you will need to handle them for
    // each state change. This should be called by the entry_action that
    // is created for the state machine.
    remove_action(1, this_object());

    if(isValidState(state) &&
       member(stateMachineData[state], "destinations") &&
       mappingp(stateMachineData[state]["destinations"]))
    {
        foreach(string destination :
                m_indices(stateMachineData[state]["destinations"]))
        {
            if(present(this_player()))
            {
                add_action("move", destination);
            }
        }
    }
}

protected nomask void addObjects(string state)
{
    // WARNING: This will remove all objects for a given state that are not
    // persistent. This should be called by the entry_action that is created
    // for the state machine. Killable things should never be persistent!
    if(isValidState(currentState) &&
       member(stateMachineData[currentState], "objects") &&
       stateMachineData[state]["objects"] &&
       mappingp(stateMachineData[currentState]["objects"]))
    {
        foreach(object o : objectList)
        {
            unregisterObject(currentState, o);
            if(objectp(o))
            {
                object *inventory = deep_inventory(o);
                foreach(object item : inventory)
                {
                    unregisterObject(currentState, item);
                    destruct(item);
                }
            }
            objectList -= ({ o });
            destruct(o);
        }

        foreach(string blueprint :
                m_values(stateMachineData[state]["objects"]))
        {
            object newObject = clone_object(blueprint);
            objectList += ({ newObject });
            move_object(newObject, this_object());
            registerObject(state, newObject);
        }
    }
}

protected nomask void addPersistentObjects()
{
    if(isValidState("default") &&
       member(stateMachineData["default"], "persistent objects") &&
       mappingp(stateMachineData["default"]["persistent objects"]))
    {
        foreach(string key : m_indices(persistentObjectList))
        {
            unregisterObject(currentState, persistentObjectList[key]);
            if(objectp(persistentObjectList[key]))
            {
                object *inventory = deep_inventory(persistentObjectList[key]);
                foreach(object item : inventory)
                {
                    unregisterPersistentObject(item);
                    destruct(item);
                }
            }
            destruct(persistentObjectList[persistentObjectList[key]]);
            m_delete(persistentObjectList, key);
        }

        foreach(mapping blueprint :
                m_indices(stateMachineData["default"]["persistent objects"]))
        {
            object newObject = clone_object(
                stateMachineData["default"]["persistent objects"][blueprint]);
            persistentObjectList[blueprint] = newObject;
            move_object(newObject, this_object());
            registerPersistentObject(newObject);
        }
    }

}

public int id(string item)
{
    int ret = 0;

    if(isValidState(currentState) &&
       member(stateMachineData[currentState], "items") &&
       mappingp(stateMachineData[currentState]["items"]))
    {
        ret = member(stateMachineData[currentState]["items"], item);
    }
    return ret;
}

public int move(string str)
{
    string direction = query_verb();

    int ret = 0;
    // Need to verify that the current state has this action.
    if(isValidState(currentState) &&
       member(stateMachineData[currentState], "destinations") &&
       mappingp(stateMachineData[currentState]["destinations"]) &&
       member(stateMachineData[currentState]["destinations"], direction))
    {
        ret = 1;
        this_player()->move_player(sprintf("%s#%s", direction,
            stateMachineData[currentState]["destinations"][direction]));
    }
    return ret;
}

public mixed query(string property)
{
    mixed ret = 0;
    if(isValidState(currentState) &&
       member(stateMachineData[currentState], "properties") &&
       mappingp(stateMachineData[currentState]["properties"]) &&
       member(stateMachineData[currentState]["properties"], property))
    {
        ret = stateMachineData[currentState]["properties"][property];
    }
    else if (property == "environment type")
    {
        ret = stateMachineData["default"]["environment type"];
    }
    return ret;
}

private nomask string formatText(int colorInfo, string text)
{
    return color(this_player()->query("term"), this_player(), colorInfo,
                 format(text, 78));
}

private nomask string parseEfunCall(string match)
{
    string ret = "ERROR";
    // This match was found to be of the form efun::type::obj::function
    // the only supported efun right now is call_other
    // type can be any of: room, key (into persistentObjects), OR filename
    // obj is either this, the key into persistentObjects, OR a file path.
    // function is a method on the called object. This method MUST return a
    // string. 
    string *arguments = explode(match, "::");
    if(sizeof(arguments) == 4)
    {
        switch(arguments[0])
        {
            case "##call_other":
            {
                switch(arguments[1])
                {
                    case "key":
                    {
                        if(member(persistentObjectList, arguments[2]) &&
                           objectp(persistentObjectList[arguments[2]]))
                        {
                            ret = call_other(persistentObjectList[arguments[2]],
                                             arguments[3]);
                        }
                        break;
                    }
                    case "filename":
                    {
                        if(file_size(arguments[2]) > 0)
                        {
                            ret = call_other(arguments[2], arguments[3]);
                        }
                        break;
                    }
                    case "room":
                    {
                        ret = call_other(this_object(), arguments[3]);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret;
}

public void long(string item)
{
    if(set_light(0) < 1)
    {
        if(this_player() && this_player()->query_property("infravision"))
        {
            write(formatText(C_PMON,"You gaze into the darkness and see:\n\n"));
        }
        else
        {
            write(formatText(C_PMON, "It is dark.\n"));
            return;
        }
    }
    if(item)
    {
        if(id(item))
        {
            write(formatText(C_ROOMS_DIRS, sprintf("%s\n",
                stateMachineData[currentState]["items"][item])));
        }
    }
    else if(isValidState(currentState))
    {
        string longDesc = formatText(C_ROOMS_SHORT,
            stateMachineData[currentState]["long"]);
 
        string roomColor = explode(color(this_player()->query("term"),
            this_player(), C_ROOMS_SHORT, "test"), "test")[0];
        // Handle efun calls in the description
        longDesc = regreplace(longDesc, ":#:", roomColor,1);
        string ss = regreplace(longDesc,
            "##([^:]+)::(key|filename|room)::([^:]+)::([a-zA-Z0-9_])+",
            #'parseEfunCall,1);

        write(ss);
        string exitDescription = "-==- There are no obvious exits.\n";
        if(member(stateMachineData[currentState], "destinations") &&
           mappingp(stateMachineData[currentState]["destinations"]))
        {
            string *exits =
                m_indices(stateMachineData[currentState]["destinations"]);

            exitDescription =
                (sizeof(exits) == 1) ? "-==- There is one obvious exit: " :
                "-==- There are multiple obvious exits: ";

            foreach(string exit :
                    m_indices(stateMachineData[currentState]["destinations"]))
            {
                exitDescription += sprintf("%s, ", exit);
            }
            exitDescription = regreplace(exitDescription, "[,:] ([a-z]+), $",
                (sizeof(exits) == 1) ? ": \\1.\n" :
                (sizeof(exits) == 2) ? " and \\1.\n" : ", and \\1.\n");

            write(formatText(C_ROOMS_DIRS, exitDescription));
        }
    }
}

public string short()
{
    string shortDesc = "";
    if((set_light(0) < 1) && !this_player()->query_property("infravision"))
    {
        shortDesc = "It is dark.\n";
    }
    
    else if(isValidState(currentState))
    {
        if(set_light(0) < 1)
        {
            shortDesc = "[Dark] ";
        }
        shortDesc += stateMachineData[currentState]["short"];

        if(member(stateMachineData[currentState], "destinations") &&
           mappingp(stateMachineData[currentState]["destinations"]))
        {
            string *exits =
                m_indices(stateMachineData[currentState]["destinations"]);

            shortDesc += " ( ";

            foreach(string exit :
                    m_indices(stateMachineData[currentState]["destinations"]))
            {
                shortDesc += regreplace(exit, "(n|s|e|w|d)(orth|outh|ast|est|own)", 
                    "\\1", 1) + " ";
            }
            shortDesc += ")";
        }
    }
    return shortDesc;
}

public void init()
{
    if(!currentState)
    {
        currentState = "default";
        addPersistentObjects();
        addObjects("default");
    }
    addExits(currentState);
    
    if(stateMachine && !stateMachine->isInitialized())
    {
        stateMachine->init();
    }
}

public void reset(int arg)
{
}

public int violenceIsProhibited()
{
    return query("no fighting");
}

