//*****************************************************************************
// Class: stateObject
// File Name: stateObject.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: All objects that are to be used by the state machine engine
//              must inherit this class. It is used for event processing and
//              the registering of related/controlled objects and persistent
//              objects - where "registered object" are only maintained for
//              specific states while persistent ones will be maintained for
//              all states within the state machine.
//
//*****************************************************************************
protected object stateMachine = 0;

//-----------------------------------------------------------------------------
// Method: setStateMachine
// Description: This method sets the state machine that will control this state
//              object.
//
// Parameters: sm - the controlling state machine
//-----------------------------------------------------------------------------
public nomask void setStateMachine(object sm)
{
    if(sm == 0)
    {
        stateMachine = 0;
    }
    else if(sm && member(inherit_list(sm),
              "/lib/core/stateMachine.c") > -1)
    {
        stateMachine = sm;
    }
}

//-----------------------------------------------------------------------------
// Method: sendStateEvent
// Description: This method sends the passed state transition event to the 
//              controlling state machine. This state transition event must
//              have an appropriately-named transition in the state machine.
//              Please see the definition of receiveEvent in the stateMachine 
//              class for more details.
//
// Parameters: event - the state to transition to.
//
// Returns: true if the state machine successfully moves to the new state.
//-----------------------------------------------------------------------------
protected nomask int sendStateEvent(string event)
{
    int ret = 0;

    if(stateMachine)
    {
        ret = stateMachine->receiveEvent(event);
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: registerObject
// Description: This method registers the supplied to the supplied state
//
// Parameters: state - the state with which to register the object
//             objectToRegister - the object to register with the state
//
// Returns: true if the state machine successfully registers the object
//-----------------------------------------------------------------------------
protected nomask int registerObject(string state, object objectToRegister)
{
    int ret = 0;
    if(stateMachine)
    {
        ret = stateMachine->registerObject(state, objectToRegister);
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: unregisterObject
// Description: This method unregisters the supplied object from the supplied
//              state.
//
// Parameters: state - the state from which to unregister the object
//             objectToRegister - the object to uregister from the state
//
// Returns: true if the state machine successfully unregisters the object
//-----------------------------------------------------------------------------
protected nomask int unregisterObject(string state, object objectToUnregister)
{
    int ret = 0;
    if(stateMachine)
    {
        ret = stateMachine->unregisterObject(state, objectToUnregister);
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: registerPersistentObject
// Description: This method registers the supplied object from all states
//              within the state machine.
//
// Parameters: objectToRegister - the object to register with all states
//
// Returns: true if the state machine successfully registers the object
//-----------------------------------------------------------------------------
protected nomask void registerPersistentObject(object objectToRegister)
{
    if(stateMachine)
    {
        stateMachine->registerPersistentObject(objectToRegister);
    }
}

//-----------------------------------------------------------------------------
// Method: unregisterPersistentObject
// Description: This method unregisters the supplied object from all states
//              within the state machine.
//
// Parameters: objectToRegister - the object to unregister from all state
//
// Returns: true if the state machine successfully unregisters the object
//-----------------------------------------------------------------------------
protected nomask void unregisterPersistentObject(object objectToUnregister)
{
    if(stateMachine)
    {
        stateMachine->unregisterPersistentObject(objectToUnregister);
    }
}
