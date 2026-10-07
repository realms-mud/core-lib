//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

private object Actor;
private object Research;
private object Owner;
private object Room;
private object Item;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");
    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor.Name("Lifecycle actor");
    Research = clone_object(
        "/lib/tests/support/services/lifecycleResearchActor.c");
    Research.Name("Lifecycle researcher");
    Research.Str(20);
    Research.Int(20);
    Research.Dex(20);
    Research.Con(20);
    Research.Wis(20);
    Research.Chr(20);
    Research.addSkillPoints(100);
    Research.advanceSkill("long sword", 10);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Item))
    {
        destruct(Item);
    }
    if (objectp(Owner))
    {
        destruct(Owner);
    }
    if (objectp(Room))
    {
        destruct(Room);
    }
    destruct(Actor);
    destruct(Research);
}

/////////////////////////////////////////////////////////////////////////////
void PointResearchRecordsOnlySuccessfulMilestones()
{
    string item = "/lib/tests/support/research/testPointsResearchItem.c";
    ExpectFalse(Research.initiateResearch(item));
    ExpectEq(0, Research.countObservations(([ "type": "research.learn" ])));
    Research.addResearchPoints(1);
    ExpectTrue(Research.initiateResearch(item));
    ExpectFalse(Research.initiateResearch(item));
    ExpectEq(1, Research.countObservations(([ "type": "research.learn" ])));
    ExpectEq(1, Research.countObservations(([ "type": "research.complete" ])));
    mapping *entries = Research.queryObservations(([
        "type": "research.complete"
    ]));
    ExpectEq(item, entries[0]["subject"]);
    ExpectEq("points", entries[0]["context"]["research type"]);
}

/////////////////////////////////////////////////////////////////////////////
void GrantedResearchRecordsLearnAndComplete()
{
    string item = "/lib/tests/support/research/testGrantedResearchItem.c";
    ExpectTrue(Research.initiateResearch(item));
    ExpectFalse(Research.initiateResearch(item));
    ExpectEq(1, Research.countObservations(([ "type": "research.learn" ])));
    ExpectEq(1, Research.countObservations(([ "type": "research.complete" ])));
}

/////////////////////////////////////////////////////////////////////////////
void TimedResearchRecordsCompletionOnlyAtMilestone()
{
    string item = "/lib/tests/support/research/testTimedResearchItem.c";
    ExpectTrue(Research.initiateResearch(item));
    ExpectEq(1, Research.countObservations(([ "type": "research.learn" ])));
    ExpectEq(0, Research.countObservations(([ "type": "research.complete" ])));
    for (int heartbeat = 0; heartbeat < 8; heartbeat++)
    {
        Research.heart_beat();
    }
    ExpectTrue(Research.isResearched(item));
    ExpectEq(1, Research.countObservations(([ "type": "research.complete" ])));
}

/////////////////////////////////////////////////////////////////////////////
void ChoiceRecordsOnlyConsumedSelection()
{
    string item = "/lib/tests/support/research/testGrantedResearchItem.c";
    ExpectFalse(Research.selectResearchChoice(item, "reward", "1"));
    ExpectTrue(Research.addResearchChoice(([
        "name": "reward",
        "description": "Choose research",
        "research objects": ({ item })
    ])));
    ExpectTrue(Research.selectResearchChoice(item, "reward", "1"));
    ExpectFalse(Research.selectResearchChoice(item, "reward", "1"));
    mapping *entries = Research.queryObservations(([
        "type": "research.choiceChosen"
    ]));
    ExpectEq(1, sizeof(entries));
    ExpectEq(item, entries[0]["subject"]);
    ExpectEq("reward", entries[0]["context"]["choice"]);
    ExpectEq("1", entries[0]["context"]["selection"]);
}

/////////////////////////////////////////////////////////////////////////////
void PathRecordsOnlyOpenedSelection()
{
    string tree = "/lib/tests/support/research/testResearchTree.c";
    ExpectFalse(Research.selectResearchPath(tree, "path", "1"));
    ExpectTrue(Research.addResearchChoice(([
        "name": "path",
        "description": "Choose a path",
        "research objects": ({ tree })
    ])));
    ExpectTrue(Research.selectResearchPath(tree, "path", "1"));
    ExpectFalse(Research.selectResearchPath(tree, "path", "1"));
    mapping *entries = Research.queryObservations(([
        "type": "research.pathChosen"
    ]));
    ExpectEq(1, sizeof(entries));
    ExpectEq(tree, entries[0]["subject"]);
    ExpectEq(({ tree }), entries[0]["context"]["research trees"]);
}

/////////////////////////////////////////////////////////////////////////////
void QuestFailureRecordsCallbacksWithoutDuplicateCompletion()
{
    string quest = "/lib/tests/support/quests/fakeQuestItem.c";
    ExpectFalse(Actor.beginQuest("/lib/tests/support/quests/nonexistent.c"));
    ExpectTrue(Actor.beginQuest(quest));
    ExpectFalse(Actor.beginQuest(quest));
    Actor.advanceQuestState(quest, "meet the king");
    ExpectEq(0, Actor.countObservations(([ "type": "quest.advanced" ])));
    Actor.advanceQuestState(quest, "met the king");
    Actor.advanceQuestState(quest, "ignore the king");
    Actor.advanceQuestState(quest, "ignore the king");
    ExpectEq(1, Actor.countObservations(([ "type": "quest.started" ])));
    ExpectEq(2, Actor.countObservations(([ "type": "quest.advanced" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "quest.completed" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "quest.failed" ])));
    ExpectEq(0, Actor.countObservations(([ "type": "quest.succeeded" ])));
    mapping *entries = Actor.queryObservations(([ "type": "quest.advanced" ]));
    ExpectEq("meet the king", entries[0]["context"]["previous state"]);
    ExpectEq("met the king", entries[0]["context"]["state"]);
}

/////////////////////////////////////////////////////////////////////////////
void QuestSuccessRecordsDistinctOutcome()
{
    string quest = "/lib/tests/support/quests/fakeQuestItem.c";
    ExpectTrue(Actor.beginQuest(quest));
    Actor.advanceQuestState(quest, "met the king");
    Actor.advanceQuestState(quest, "serve the king");
    Actor.advanceQuestState(quest, "save the king");
    ExpectEq(1, Actor.countObservations(([ "type": "quest.completed" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "quest.succeeded" ])));
    ExpectEq(0, Actor.countObservations(([ "type": "quest.failed" ])));
}

/////////////////////////////////////////////////////////////////////////////
void StateRecordsOnlyActualChanges()
{
    Research.onStateChanged(0, "ignored");
    Research.onStateChanged(Actor, "first");
    Research.onStateChanged(Actor, "first");
    Research.onStateChanged(Actor, "second");
    mapping *entries = Research.queryObservations(([ "type": "state.changed" ]));
    ExpectEq(2, sizeof(entries));
    ExpectEq("first", entries[1]["context"]["previous state"]);
    ExpectEq("second", entries[1]["context"]["state"]);
    ExpectEq("second", Research.stateFor(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void FactionRecordsMembershipAndOnlyChangedDispositions()
{
    string faction = "/lib/tests/support/factions/testFaction.c";
    Actor.updateFactionDisposition(faction, 0);
    ExpectEq("neutral", Actor.factionDispositionToward(faction));
    ExpectEq(0, Actor.countObservations(([
        "type": "faction.dispositionChanged"
    ])));
    Actor.updateFactionDisposition(faction, 1);
    ExpectEq(0, Actor.countObservations(([
        "type": "faction.dispositionChanged"
    ])));
    ExpectTrue(Actor.joinFaction(faction));
    ExpectFalse(Actor.joinFaction(faction));
    ExpectTrue(Actor.leaveFaction(faction));
    ExpectFalse(Actor.leaveFaction(faction));
    ExpectFalse(Actor.joinFaction(
        "/lib/tests/support/factions/nonexistent.c"));
    ExpectEq(1, Actor.countObservations(([ "type": "faction.joined" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "faction.left" ])));
    ExpectEq(2, Actor.countObservations(([
        "type": "faction.dispositionChanged"
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void FactionDispositionUpdateRecordsActualTransition()
{
    string faction = "/lib/tests/support/factions/testFaction.c";
    Actor.updateFactionDisposition(faction, 5, 1);
    ExpectEq("hostile", Actor.factionDispositionToward(faction));
    Actor.updateFactionDisposition(faction, 0);
    mapping *entries = Actor.queryObservations(([
        "type": "faction.dispositionChanged"
    ]));
    ExpectEq(1, sizeof(entries));
    ExpectEq("neutral", entries[0]["context"]["previous disposition"]);
    ExpectEq("hostile", entries[0]["context"]["disposition"]);
}

/////////////////////////////////////////////////////////////////////////////
void CraftingRecordsStartCompleteAndAbortWithStableSubject()
{
    Actor.completeCrafting();
    Actor.abortCrafting();
    Item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    string itemPath = program_name(Item);
    Actor.itemBeingCrafted(Item);
    Actor.itemBeingCrafted(Item);
    Actor.completeCrafting();
    Actor.completeCrafting();
    ExpectEq(1, Actor.countObservations(([ "type": "craft.started" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "craft.completed" ])));
    Actor.itemBeingCrafted(Item);
    Actor.abortCrafting();
    Actor.abortCrafting();
    mapping *entries = Actor.queryObservations(([ "type": "craft.aborted" ]));
    ExpectEq(1, sizeof(entries));
    ExpectEq(itemPath, entries[0]["subject"]);
    ExpectEq(2, Actor.countObservations(([ "type": "craft.started" ])));
}

/////////////////////////////////////////////////////////////////////////////
void FactionReputationRecordsFinalValuesAndSuppressesNoOps()
{
    string faction = "/lib/tests/support/factions/testFaction.c";
    Actor.updateFactionDisposition(faction, 0);
    ExpectEq(0, Actor.countObservations(([
        "type": "faction.reputationChanged"
    ])));
    Actor.updateFactionDisposition(faction, 1);
    Actor.updateFactionDisposition(faction, 0);
    mapping *entries = Actor.queryObservations(([
        "type": "faction.reputationChanged"
    ]));
    ExpectEq(1, sizeof(entries));
    ExpectEq(0, entries[0]["context"]["previous reputation"]);
    ExpectEq(1, entries[0]["context"]["reputation"]);
    ExpectTrue(Actor.joinFaction(faction));
    ExpectTrue(Actor.leaveFaction(faction));
    entries = Actor.queryObservations(([
        "type": "faction.reputationChanged"
    ]));
    ExpectEq(2, sizeof(entries));
    ExpectEq(1, entries[1]["context"]["previous reputation"]);
    ExpectEq(-999, entries[1]["context"]["reputation"]);
}

/////////////////////////////////////////////////////////////////////////////
void CraftingSnapshotsSurviveMutationAndDestruction()
{
    Item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    mapping materials = ([
        "blade": ([ "type": "Type XIII", "metal": "steel" ])
    ]);
    Item->set("crafting materials", materials);
    Item->set("craftsmanship", 77);
    Actor.itemBeingCrafted(Item);
    Actor.completeCrafting();
    Item->set("craftsmanship", 35);
    Item->set("crafting materials", ([
        "blade": ([ "type": "Type XIII", "metal": "iron" ])
    ]));
    mapping *entries = Actor.queryObservations(([
        "type": "craft.completed"
    ]));
    ExpectEq("long sword", entries[0]["context"]["blueprint"]);
    ExpectEq("long sword", entries[0]["context"]["recipe"]);
    ExpectEq(materials, entries[0]["context"]["materials"]);
    ExpectEq(77, entries[0]["context"]["craftsmanship"]);
    Actor.itemBeingCrafted(Item);
    Actor.abortCrafting();
    ExpectFalse(objectp(Item));
    entries = Actor.queryObservations(([ "type": "craft.aborted" ]));
    ExpectEq("iron", entries[0]["context"]["materials"]["blade"]["metal"]);
    ExpectEq(35, entries[0]["context"]["craftsmanship"]);
}

/////////////////////////////////////////////////////////////////////////////
void ContextUsesActualActorAndCalendarFacts()
{
    object calendar = getService("environment");
    mapping context = getService("experiences")->buildObservationContext(
        Actor, ([ "type": "movement.enter" ]));
    ExpectEq(Actor.Race(), context["race"]);
    ExpectEq(Actor.memberOfGuilds(), context["guilds"]);
    ExpectEq(Actor.Factions(), context["factions"]);
    ExpectEq(calendar->currentTime(), context["minutes after midnight"]);
    ExpectEq(calendar->currentDay(), context["day"]);
    ExpectEq(calendar->currentYear(), context["year"]);
    ExpectFalse(member(context, "equipment"));
    ExpectFalse(member(context, "weather"));
    ExpectFalse(member(context, "stance"));
}

/////////////////////////////////////////////////////////////////////////////
void RecordingCapturesContextWithoutProducerCallingHelper()
{
    object calendar = getService("environment");
    mapping entry = Actor.recordObservation(([
        "type": "social.emote",
        "context": ([ "action": "smile", "explicit": 1 ])
    ]));
    ExpectEq(Actor.Race(), entry["context"]["race"]);
    ExpectEq(calendar->currentTime(),
        entry["context"]["minutes after midnight"]);
    ExpectEq("smile", entry["context"]["action"]);
    entry = Actor.recordObservation(([
        "type": "research.complete",
        "context": ([ "minutes after midnight": 1439 ])
    ]));
    ExpectEq(1439, entry["context"]["minutes after midnight"]);
    ExpectTrue(member(entry["context"], "equipment"));
    ExpectTrue(member(entry["context"], "effects"));
}

/////////////////////////////////////////////////////////////////////////////
void CraftingFailedAttemptIsNotAnAbortOrCompletion()
{
    Item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    Item->set("crafting in progress", 1);
    Item->set("crafting materials", ([
        "blade": ([
            "type": "Type XIII",
            "metal": "steel"
        ])
    ]));
    ExpectTrue(sizeof(getService("crafting")->materialsUsedForCrafting(Item)));
    Actor.itemBeingCrafted(Item);
    ExpectFalse(getService("crafting")->craftItem(Item, Actor));
    ExpectEq(1, Actor.countObservations(([ "type": "craft.failed" ])));
    ExpectEq(0, Actor.countObservations(([ "type": "craft.aborted" ])));
    ExpectEq(0, Actor.countObservations(([ "type": "craft.completed" ])));
    ExpectEq(Item, Actor.itemBeingCrafted());
    mapping *entries = Actor.queryObservations(([ "type": "craft.failed" ]));
    ExpectEq("steel", entries[0]["context"]["materials"]["blade"]["metal"]);
    ExpectTrue(sizeof(entries[0]["context"]["materials used"]));
}

/////////////////////////////////////////////////////////////////////////////
void ConversationRecordsExplicitStartAndAcceptedResponse()
{
    Room = clone_object("/lib/tests/support/environment/fakeEnvironment.c");
    Owner = clone_object("/lib/tests/support/services/mockNPC.c");
    Owner.Name("Lifecycle speaker");
    move_object(Actor, Room);
    move_object(Owner, Room);
    Owner.testAddConversation(
        "/lib/tests/support/conversations/testConversation.c");
    efun::set_this_player(Actor);
    ExpectTrue(Owner.beginConversation(Actor));
    ExpectEq(1, Actor.countObservations(([ "type": "conversation.started" ])));
    command("99", Actor);
    ExpectEq(0, Actor.countObservations(([ "type": "conversation.response" ])));
    command("1", Actor);
    ExpectEq(1, Actor.countObservations(([ "type": "conversation.response" ])));
    ExpectEq(1, Actor.countObservations(([ "type": "conversation.started" ])));
    Owner.onTriggerConversation(Actor, "start quest");
    command("1", Actor);
    ExpectEq(2, Actor.countObservations(([ "type": "conversation.started" ])));
    ExpectEq(2, Actor.countObservations(([ "type": "conversation.response" ])));
    mapping *entries = Actor.queryObservations(([
        "type": "conversation.response"
    ]));
    ExpectEq("first conversation#OK...", entries[0]["context"]["response"]);
}

/////////////////////////////////////////////////////////////////////////////
void SustainedUseAndDeactivationRecordOnlyTransitions()
{
    string path = "/lib/tests/support/research/testSustainedTraitResearch.c";
    ExpectTrue(Actor.initiateResearch(path));
    object item = getService("research")->researchObject(path);
    ExpectTrue(Actor.activateSustainedResearch(item));
    ExpectFalse(Actor.activateSustainedResearch(item));
    ExpectEq(1, Actor.countObservations(([ "type":"research.use" ])));
    ExpectTrue(Actor.deactivateSustainedResearch(path));
    ExpectFalse(Actor.deactivateSustainedResearch(path));
    ExpectEq(1, Actor.countObservations(([
        "type":"research.deactivated"
    ])));
    ExpectFalse(Actor.activateSustainedResearch(item));
    ExpectEq(1, Actor.countObservations(([ "type":"research.use" ])));
}