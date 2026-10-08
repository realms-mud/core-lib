//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Npc;
object Prerequisite;

void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("alice");
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    Prerequisite = clone_object("/lib/tests/support/research/prerequisiteItem.c");
}

void CleanUp()
{
    destruct(Prerequisite);
    destruct(Npc);
    destruct(Player);
}

void NamedNpcAttitudesSurviveRespawnWithoutSharingPlayers()
{
    Npc.modifyRelationship(Player, "trust", 10);
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("bob");
    ExpectEq(0, Npc.relationshipValue(other, "trust"));
    ExpectEq(0, Player.relationshipValue(Npc, "trust"));
    destruct(Npc);
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    ExpectEq(10, Npc.relationshipValue(Player, "trust"));
    ExpectEq(0, Npc.relationshipValue(other, "trust"));
    destruct(other);
}

void QuestUnlocksExactIncomingRelationshipPrerequisiteOnce()
{
    string lesson = "/lib/tests/support/relationships/research.c";
    ExpectFalse(Player.canResearch(lesson));
    string identity = getService("relationship")->identity(Npc);
    ExpectTrue(Prerequisite.AddTestPrerequisite("chen trusts me", ([
        "type":"relationship",
        "direction":"from",
        "target":identity,
        "dimension":"trust",
        "minimum":10
    ])));
    ExpectFalse(Prerequisite.checkPrerequisites(Player));
    string quest = "/lib/tests/support/relationships/quest.c";
    ExpectTrue(Player.beginQuest(quest));
    ExpectTrue(Player.advanceQuestState(quest, "complete"));
    ExpectEq(10, Npc.relationshipValue(Player, "trust"));
    ExpectTrue(Prerequisite.checkPrerequisites(Player));
    ExpectTrue(Player.initiateResearch(lesson));
    ExpectTrue(Player.isResearched(lesson));
    ExpectEq(1, Player.countObservations(([ "type":"quest.completed" ])));
    ExpectEq(1, Player.countObservations(([ "type":"quest.relationship" ])));
    Player.advanceQuestState(quest, "complete");
    ExpectEq(10, Npc.relationshipValue(Player, "trust"));
}

void MissingAndMalformedPrerequisiteDataFailClosed()
{
    ExpectFalse(Prerequisite.AddTestPrerequisite("bad", ([
        "type":"relationship",
        "direction":"from",
        "target":"Chen",
        "dimension":"trust",
        "minimum":10
    ])));
    ExpectFalse(Prerequisite.AddTestPrerequisite("bad", ([
        "type":"relationship",
        "direction":"both",
        "target":"owner",
        "dimension":"trust",
        "minimum":10
    ])));
}

void LimitorsCheckTargetDirectionAndInclusiveThresholds()
{
    object service = getService("limitor");
    mapping rule = ([
        "relationship":([
            "target":"target",
            "direction":"from",
            "dimension":"trust",
            "minimum":10,
            "maximum":20
        ])
    ]);
    ExpectTrue(service.validLimitor(rule));
    ExpectFalse(service.userFactorsMet(([ "limited by":rule ]), Player, Npc));
    Npc.modifyRelationship(Player, "trust", 10);
    ExpectTrue(service.userFactorsMet(([ "limited by":rule ]), Player, Npc));
    Npc.modifyRelationship(Player, "trust", 11);
    ExpectFalse(service.userFactorsMet(([ "limited by":rule ]), Player, Npc));
}

void OnlyAuthoredInteractionsChangeAttitudes()
{
    ExpectFalse(Npc.relationshipInteraction(Player, "social.hug", ([])));
    ExpectFalse(Npc.hasRelationship(Player));
    ExpectTrue(Npc.relationshipInteraction(Player, "social.bow", ([])));
    ExpectEq(1, Npc.relationshipValue(Player, "respect"));
    ExpectEq(0, Npc.relationshipValue(Player, "trust"));
}

void StructuredSocialAndGiftCommandsApplyOnlySuccessfulAuthoredRules()
{
    Player.Race("human");
    Player.Gender("male");
    Player.colorConfiguration("none");
    Player.addCommands();
    move_object(Player, this_object());
    move_object(Npc, this_object());
    ExpectTrue(Player.executeCommand("bow chen"));
    ExpectEq(1, Npc.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([ "type":"social.emote" ])));
    Player.executeCommand("bow missing");
    ExpectEq(1, Npc.relationshipValue(Player, "respect"));
    object gift = clone_object("/lib/tests/support/items/testSword.c");
    move_object(gift, Player);
    ExpectTrue(Player.executeCommand("give sword to chen"));
    ExpectEq(Npc, environment(gift));
    ExpectEq(5, Npc.relationshipValue(Player, "gratitude"));
    ExpectEq(1, Player.countObservations(([ "type":"gift.given" ])));
    destruct(gift);
}

void TeachingRequiresKnowledgeAndSuccessfulResearch()
{
    string item = "/lib/tests/support/research/testGrantedResearchItem.c";
    ExpectFalse(Player.learnResearchFrom(Npc, item));
    ExpectTrue(Npc.initiateResearch(item));
    ExpectTrue(Player.learnResearchFrom(Npc, item));
    ExpectEq(2, Npc.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    ExpectFalse(Player.learnResearchFrom(Npc, item));
    ExpectEq(2, Npc.relationshipValue(Player, "respect"));
}

void FactionEffectsRequireAnExplicitWitnessAndAuthoredRule()
{
    string faction = "/lib/tests/support/factions/goodGuys.c";
    Player.updateFactionDisposition(faction, 10);
    ExpectEq(0, Npc.relationshipValue(Player, "trust"));
    Player.updateFactionDisposition(faction, 10, 0, Npc);
    ExpectEq(3, Npc.relationshipValue(Player, "trust"));
    Player.updateFactionDisposition(faction, 0, 0, Npc);
    ExpectEq(3, Npc.relationshipValue(Player, "trust"));
}

void AuthoredInterpersonalTradeRecordsEvidenceAndIncomingTruth()
{
    Player.recordRelationshipInteraction(Npc, "trade.completed",
        ([ "trust":3, "respect":2 ]), ([ "item":"supplies" ]), "from");
    ExpectEq(3, Npc.relationshipValue(Player, "trust"));
    ExpectEq(0, Player.relationshipValue(Npc, "trust"));
    ExpectEq(1, Player.countObservations(([ "type":"trade.completed" ])));
}
