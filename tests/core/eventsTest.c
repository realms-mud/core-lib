//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Events;
object Subscriber;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Events = clone_object("/lib/core/events");
    Subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Subscriber);
    destruct(Events);
}

/////////////////////////////////////////////////////////////////////////////
void RegisterEventRegistersASubscriber()
{
    ExpectTrue(Events->registerEvent(Subscriber));
}

/////////////////////////////////////////////////////////////////////////////
void RegisterEventDoesNotRegisterSubscribersMoreThanOnce()
{
    ExpectTrue(Events->registerEvent(Subscriber), "first subscription");
    ExpectFalse(Events->registerEvent(Subscriber), "second subscription");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnDeathFiresEventToSubscriberOnDeathMethod()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onDeath called";
    string err = catch (Events->notify("onDeath"));
    ExpectEq(expected, err, "onDeath called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnHeartBeatFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onHeartBeat called";
    string err = catch (Events->notify("onHeartBeat"));
    ExpectEq(expected, err, "onHeartBeat called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnAttackFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onAttack called";
    string err = catch (Events->notify("onAttack"));
    ExpectEq(expected, err, "onAttack called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnAttackedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onAttacked called";
    string err = catch (Events->notify("onAttacked"));
    ExpectEq(expected, err, "onAttacked called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnMoveFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onMove called";
    string err = catch (Events->notify("onMove"));
    ExpectEq(expected, err, "onMove called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnUsedAbilityFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onUsedAbility called";
    string err = catch (Events->notify("onUsedAbility"));
    ExpectEq(expected, err, "onUsedAbility called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnHitPointsChangedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onHitPointsChanged called";
    string err = catch (Events->notify("onHitPointsChanged"));
    ExpectEq(expected, err, "onHitPointsChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnSpellPointsChangedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onSpellPointsChanged called";
    string err = catch (Events->notify("onSpellPointsChanged"));
    ExpectEq(expected, err, "onSpellPointsChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnStaminaPointsChangedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onStaminaPointsChanged called";
    string err = catch (Events->notify("onStaminaPointsChanged"));
    ExpectEq(expected, err, "onStaminaPointsChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnRunAwayFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onRunAway called";
    string err = catch (Events->notify("onRunAway"));
    ExpectEq(expected, err, "onRunAway called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnEquipFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onEquip called";
    string err = catch (Events->notify("onEquip"));
    ExpectEq(expected, err, "onEquip called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnUnequipFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onUnequip called";
    string err = catch (Events->notify("onUnequip"));
    ExpectEq(expected, err, "onUnequip called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnRegisterItemFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onRegisterItem called";
    string err = catch (Events->notify("onRegisterItem"));
    ExpectEq(expected, err, "onRegisterItem called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnUnregisterItemFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onUnregisterItem called";
    string err = catch (Events->notify("onUnregisterItem"));
    ExpectEq(expected, err, "onUnregisterItem called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnAdvancedLevelFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onAdvancedLevel called";
    string err = catch (Events->notify("onAdvancedLevel"));
    ExpectEq(expected, err, "onAdvancedLevel called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnAdvancedRankFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onAdvancedRank called";
    string err = catch (Events->notify("onAdvancedRank"));
    ExpectEq(expected, err, "onAdvancedRank called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnDemotedRankFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onDemotedRank called";
    string err = catch (Events->notify("onDemotedRank"));
    ExpectEq(expected, err, "onDemotedRank called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnJoinGuildFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onJoinGuild called";
    string err = catch (Events->notify("onJoinGuild"));
    ExpectEq(expected, err, "onJoinGuild called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnLeaveGuildFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onLeaveGuild called";
    string err = catch (Events->notify("onLeaveGuild"));
    ExpectEq(expected, err, "onLeaveGuild called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnResearchPointsAddedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onResearchPointsAdded called";
    string err = catch (Events->notify("onResearchPointsAdded"));
    ExpectEq(expected, err, "onResearchPointsAdded called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnResearchStartedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onResearchStarted called";
    string err = catch (Events->notify("onResearchStarted"));
    ExpectEq(expected, err, "onResearchStarted called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnResearchCompletedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onResearchCompleted called";
    string err = catch (Events->notify("onResearchCompleted"));
    ExpectEq(expected, err, "onResearchCompleted called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnResearchTreeOpenFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onResearchTreeOpen called";
    string err = catch (Events->notify("onResearchTreeOpen"));
    ExpectEq(expected, err, "onResearchTreeOpen called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnCombatDelayedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onCombatDelayed called";
    string err = catch (Events->notify("onCombatDelayed"));
    ExpectEq(expected, err, "onCombatDelayed called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnHitFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onHit called, data: 25, caller: lib/core/events.c";
    string err = catch (Events->notify("onHit", "25"));
    ExpectEq(expected, err, "onHit called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnTraitAddedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onTraitAdded called";
    string err = catch (Events->notify("onTraitAdded"));
    ExpectEq(expected, err, "onTraitAdded called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnTraitRemovedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onTraitRemoved called";
    string err = catch (Events->notify("onTraitRemoved"));
    ExpectEq(expected, err, "onTraitRemoved called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestStartedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestStarted called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestStarted", "blah"));
    ExpectEq(expected, err, "onQuestStarted called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestAdvancedStateFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestAdvancedState called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestAdvancedState", "blah"));
    ExpectEq(expected, err, "onQuestAdvancedState called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestCompletedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestCompleted called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestCompleted", "blah"));
    ExpectEq(expected, err, "onQuestCompleted called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestFailedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestFailed called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestFailed", "blah"));
    ExpectEq(expected, err, "onQuestFailed called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestSucceededFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestSucceeded called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestSucceeded", "blah"));
    ExpectEq(expected, err, "onQuestSucceeded called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestActivatedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestActivated called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onQuestActivated", "blah"));
    ExpectEq(expected, err, "onQuestActivated called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnQuestDeactivatedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onQuestDeactivated called: quest -> placate the lemmings, state -> find cliff";
    string err = catch (Events->notify("onQuestDeactivated", ({ "placate the lemmings", "find cliff" })));
    ExpectEq(expected, err, "onQuestDeactivated called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void UnegisterEventReturnsZeroIfNotSubscribed()
{
    ExpectFalse(Events->unregisterEvent(Subscriber));
}

/////////////////////////////////////////////////////////////////////////////
void UnegisterEventUnregistersEventHandler()
{
    Events->registerEvent(Subscriber);
    ExpectTrue(Events->unregisterEvent(Subscriber));
}

/////////////////////////////////////////////////////////////////////////////
void NotificationsDoNotGetSentOnceSubscriberUnregistered()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onCombatDelayed called";
    string err = catch (Events->notify("onCombatDelayed"));
    ExpectEq(expected, err, "onCombatDelayed called on subscriber");

    ExpectTrue(Events->unregisterEvent(Subscriber));
    Events->notify("onCombatDelayed");
}

/////////////////////////////////////////////////////////////////////////////
void UnegisteredCustomEventsNotExecuted()
{
    Events->registerEvent(Subscriber);
    Events->notify("customEventHandler");
}

/////////////////////////////////////////////////////////////////////////////
void CanRegisterCustomEventHandler()
{
    ExpectTrue(Events->registerEventHandler("customEventHandler"));
    Events->registerEvent(Subscriber);

    string expected = "*event handler: customEventHandler called: blah";
    string err = catch (Events->notify("customEventHandler", "blah"));
    ExpectEq(expected, err, "customEventHandler called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void CannotRegisterCustomEventMoreThanOnce()
{
    ExpectTrue(Events->registerEventHandler("customEventHandler"));
    ExpectFalse(Events->registerEventHandler("customEventHandler"));
}

/////////////////////////////////////////////////////////////////////////////
void CustomEventHandlerNotCalledAfterUnregistering()
{
    ExpectTrue(Events->registerEventHandler("customEventHandler"));
    Events->registerEvent(Subscriber);

    string expected = "*event handler: customEventHandler called: blah";
    string err = catch (Events->notify("customEventHandler", "blah"));
    ExpectEq(expected, err, "customEventHandler called on subscriber");

    ExpectTrue(Events->unregisterEventHandler("customEventHandler"));
    Events->notify("customEventHandler", "blah");
}

/////////////////////////////////////////////////////////////////////////////
void DeletedButNotUnregisteredSubscribersPruned()
{
    Events->registerEvent(Subscriber);
    destruct(Subscriber);
    Events->notify("onQuestSucceeded", "blah");
}

/////////////////////////////////////////////////////////////////////////////
void NotifOnSkillAdvancedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onSkillAdvanced called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onSkillAdvanced", "blah"));
    ExpectEq(expected, err, "onSkillAdvanced called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifOnSkillDecreasedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onSkillDecreased called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onSkillDecreased", "blah"));
    ExpectEq(expected, err, "onSkillDecreased called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnSkillPointsIncreasedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onSkillPointsIncreased called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onSkillPointsIncreased", "blah"));
    ExpectEq(expected, err, "onSkillPointsIncreased called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void NotifyOnSkillPointsUsedFiresEventToSubscriber()
{
    Events->registerEvent(Subscriber);

    string expected = "*event handler: onSkillPointsUsed called, data: blah, caller: lib/core/events.c";
    string err = catch (Events->notify("onSkillPointsUsed", "blah"));
    ExpectEq(expected, err, "onSkillPointsUsed called on subscriber");
}

