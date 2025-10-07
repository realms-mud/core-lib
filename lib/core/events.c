// *****************************************************************************
// Class: events
// File Name: events.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This is an admittedly rudimentary event handling system (for
//              those who live in the software development world, it's a 
//              reactor pattern) that has been designed with only the 
//              player/NPC object model in mind. Event subscribers (those
//              waiting for something to happen) can be any object, though said
//              object will only find the event processing useful if it has
//              implemented a method named as one of the strings listed in the
//              validEventHandlers array. These are the events that the
//              player/NPC will broadcast to the registered objects.
//              
// *****************************************************************************
#include <functionlist.h>

// I suspect there will be more. This, however, is a decent starting point.
private nosave string *validEventHandlers = ({ "onDeath", "onHeartBeat", 
    "onAttack", "onAttacked", "onMove", "onUsedAbility", "onHitPointsChanged",
    "onSpellPointsChanged", "onStaminaPointsChanged", "onRunAway", "onEquip",
    "onUnequip", "onRegisterItem", "onUnregisterItem", "onAdvancedLevel",
    "onAdvancedRank", "onDemotedRank", "onJoinGuild", "onLeaveGuild",
    "onResearchPointsAdded", "onResearchStarted", "onResearchCompleted",
    "onResearchTreeOpen", "onResearchChoiceAvailable", "onResearchChoiceChosen",
    "onResearchPathChosen", "onCombatDelayed", "onHit", "onTraitAdded",
    "onTraitRemoved", "onQuestStarted", "onQuestAdvancedState", 
    "onQuestCompleted", "onQuestSucceeded", "onQuestFailed", "onQuestActivated",
    "onQuestDeactivated", "onSkillAdvanced", "onSkillDecreased", 
    "onSkillPointsIncreased", "onSkillPointsUsed", "onIntoxicationChanged",
    "onStuffedChanged", "onDruggedChanged", "onSoakedChanged", "onDrunk",
    "onSober", "onDetoxified", "onWastedOnDrugs", "onNoLongerDrugged", "onSoaked",
    "onNoLongerSoaked", "onCannotEatMore", "onHungry", "onBeginDetox",
    "onSaveSucceeded", "onRestoreSucceeded", "onRestoreFailed", "onStateChanged",
    "onConversationResponse", "receiveEvent", "onCraftingStarted", 
    "onCraftingCompleted", "onCraftingAborted", "onTriggerConversation",
    "onMessageReceived", "onConstructionStarted", "onConstructionCompleted",
    "onDestructed", "onCreationIncomplete", "onLeavingGame", "onRecalculating"
});
    
private nosave mapping eventList = ([ ]);

//-----------------------------------------------------------------------------
// Method: registerEvent
// Description: This method is used to register event handlers that will
//              subscribe to a given event. The object can be of any base type.
//              If an event handler as defined in validEventHandlers exists
//              in this subscriber object, it will be called when the event
//              of the same name occurs.
//
// Parameters: subscriber - the object that will subscribe to events
//
// Returns: true if successful.
//-----------------------------------------------------------------------------
public nomask int registerEvent(object subscriber)
{
    int ret = 0;
    if(subscriber && objectp(subscriber) && !member(eventList, subscriber))
    {
        string *eventsToAdd = ({ });
        string *functions = functionlist(subscriber, RETURN_FUNCTION_NAME);

        foreach(string method in functions)
        {
            if(method && stringp(method) && 
              (member(validEventHandlers, method) > -1))
            {
                eventsToAdd += ({ method });
                ret = 1;
            }
        }
        if(ret)
        {
            eventList[subscriber] = eventsToAdd;
        }
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: unregisterEvent
// Description: This method is used to unregister event handlers.
//
// Parameters: subscriber - the object that will unsubscribe to events
//
// Returns: true if successful.
//-----------------------------------------------------------------------------
public nomask int unregisterEvent(object subscriber)
{
    int ret = 0;
    if(subscriber && objectp(subscriber) && member(eventList, subscriber))
    {
        m_delete(eventList, subscriber);   
        ret = 1;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: registerEventHandler
// Description: This method is used to register custom events that can then be
//              subscribed to by event handlers. These events are then placed
//              in the validEventHandlers list.
//
// Parameters: eventHandler - new event to manage
//
// Returns: true if successful.
//-----------------------------------------------------------------------------
public nomask int registerEventHandler(string eventHandler)
{
    int ret = 0;
    if(eventHandler && stringp(eventHandler) && 
       (member(validEventHandlers, eventHandler) < 0))
    {
        validEventHandlers += ({ eventHandler });
        ret = 1;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: unregisterEventHandler
// Description: This method is used to unregister custom events.
//
// Parameters: eventHandler - new event to manage
//
// Returns: true if successful.
//-----------------------------------------------------------------------------
public nomask int unregisterEventHandler(string eventHandler)
{
    int ret = 0;
    if(eventHandler && stringp(eventHandler) && 
       (member(validEventHandlers, eventHandler) > -1))
    {
        validEventHandlers -= ({ eventHandler });
        ret = 1;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: notify
// Description: This method is used to send notifications to all registered
//              event handlers. Every event handler that has created a method
//              of same name as the event that is passed will have that method
//              called with this_object() passed as a parameter.
//
// Parameters: event - the event that subscribers will be notified of as having
//                     occurred. This event must be defined in 
//                     the validEventHandlers array.
//
// Returns: true if successful.
//-----------------------------------------------------------------------------
public varargs nomask int notify(string event, mixed message)
{
    int ret = 0;
    
    // It may seem weird to check this_object() here, but this can get called
    // from a call_out while the object is getting destructed.
    if(event && stringp(event) && (member(validEventHandlers, event) > -1) &&
        this_object())
    {
        // delete all null handlers
        m_delete(eventList, 0);
        
        // May want/need to limit calls of this method
        object *filteredEvents = filter(m_indices(eventList),
            (: (objectp($1) && 
                (member(eventList[$1], $2) > -1) &&
                function_exists($2, $1)) :), event);

        foreach(object handler in filteredEvents)
        {
            call_out("processEventCallOut", 0, handler, event, message);
            ret = 1;
        }

        filteredEvents = filter(m_indices(eventList),
            (: (objectp($1) && function_exists("receiveEvent", $1)) :));

        foreach(object handler in filteredEvents)
        {
            call_out("processEventCallOut", 0, handler, event, message, 1);
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs nomask int notifySynchronous(string event, mixed message)
{
    int ret = 0;

	// It may seem weird to check this_object() here, but this can get called
	// from a call_out while the object is getting destructed.
    if (event && stringp(event) && (member(validEventHandlers, event) > -1) &&
        this_object())
    {
        // delete all null handlers
        m_delete(eventList, 0);

        // May want/need to limit calls of this method
        object *filteredEvents = filter(m_indices(eventList),
            (: (objectp($1) && function_exists("receiveEvent", $1)) :));

        call_direct(filteredEvents, "receiveEvent", this_object(), event, message);

        filteredEvents = filter(m_indices(eventList),
            (: (objectp($1) && function_exists(event, $1) &&
            (member(eventList[$1], $2) > -1) &&
                function_exists($2, $1)) :), event);

        call_direct(filteredEvents, event, this_object(), message);

        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void processEventCallOut(object handler, string event,
    mixed message, int isGenericHandler)
{
    if (objectp(handler))
    {
        if (isGenericHandler)
        {
            call_other(handler, "receiveEvent", this_object(), event, message);
        }
        else
        {
            call_other(handler, event, this_object(), message);
        }
    }
}
