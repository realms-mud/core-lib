//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping StateMachineRegistry = ([]);
private nosave string BaseStateMachine = "/lib/core/stateMachine.c";

///////////////////////////////////////////////////////////////////////////////
public nomask int validateStateMachine(string path)
{
    int ret = 0;
    if (path && (file_size(path) > 0))
    {
        object stateMachine = load_object(path);
        ret = (member(inherit_list(stateMachine), BaseStateMachine) > -1);
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////
public nomask varargs object getStateMachine(string stateMachinePath,
    string owner)
{
    object ret = 0;
    string stateMachineKey = owner ? owner : "default";

    if (validateStateMachine(stateMachinePath))
    {
        if (!member(StateMachineRegistry, stateMachinePath))
        {
            StateMachineRegistry[stateMachinePath] = ([]);
        }

        if (member(StateMachineRegistry[stateMachinePath], stateMachineKey) &&
            objectp(StateMachineRegistry[stateMachinePath][stateMachineKey]))
        {
            ret = StateMachineRegistry[stateMachinePath][stateMachineKey];
        }
        else
        {
            ret = clone_object(stateMachinePath);
            StateMachineRegistry[stateMachinePath][stateMachineKey] = ret;
        }
    }

    return ret;
}
