//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

// Valid keys for each state:
// entry_action - function called on entry into state
// exit_action - function called on exit from state
// transitions - mapping of transitions:
//                  - key is event that could trigger the transition
//                  - value is mapping of event conditions:
//                        - guard is the object/method that blocks transition
//                        - state is the state to transition to
// NOTE: It would be very bad form to have a non-persistent object as a guard!
//       If, for example, a monster's death frees a guard, maintain ownership
//       in the room and check from there. It's more trouble than it's worth
//       to protect against "vanishing" guards. You've been warned.
protected mapping states = ([
//    "layout": ([
//        "entry_action": "",
//        "exit_action": "",
//        "transitions": ([
//            "some event": ([        
//                "guard": 0;0,
//                "state": "";0
//            ])
//        ])
//    ])
]);

protected string state = "default";

protected mapping objectList = ([]);
    
/////////////////////////////////////////////////////////////////////////////
private nomask int stateHasObjectList(string state)
{
    return (member(states, state) && member(objectList, state));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int registerObject(string state, object objectToCheck)
{
    int ret = 0;
     
    if(objectToCheck && stateHasObjectList(state))
    {
        objectList[state] += ({ objectToCheck });
        objectToCheck->setStateMachine(this_object());
        ret = 1;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int unregisterObject(string state, object objectToCheck)
{
    int ret = 0;

    if(objectToCheck && stateHasObjectList(state) &&
       (member(objectList[state], objectToCheck) > -1))
    {
        objectList[state] -= ({ objectToCheck });
        objectToCheck->setStateMachine(0);
        ret = 1;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void registerPersistentObject(object o)
{
    foreach(string s : m_indices(states))
    {
        registerObject(s, o);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unregisterPersistentObject(object o)
{
    foreach(string s : m_indices(states))
    {
        unregisterObject(s, o);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void onEnter()
{
    if(stateHasObjectList(state) && member(states[state], "entry_action"))
    {
        filter_objects(objectList[state], states[state]["entry_action"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void onExit()
{
    if(stateHasObjectList(state) && member(states[state], "exit_action"))
    {
        filter_objects(objectList[state], states[state]["exit_action"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int receiveEvent(string event)
{
    int ret = 0;
    if(member(states[state], "transitions") &&
       member(states[state]["transitions"], event) &&
       member(states[state]["transitions"][event], "guard") && 
       states[state]["transitions"][event]["guard", 0] &&
       call_other(states[state]["transitions"][event]["guard", 0],
                  states[state]["transitions"][event]["guard", 1]))
     {
         onExit();
         state = states[state]["transitions"][event]["state",0];
         onEnter();
         ret = 1;
     }
     return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    foreach(string s : m_indices(states))
    {
        while(member(objectList[s], 0) > -1)
        {
            objectList[s] -= ({ 0 });
        }
    }
}


