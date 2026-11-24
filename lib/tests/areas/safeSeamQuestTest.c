//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
string QuestPath = "/areas/minlach/quests/safe-seam.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("safeseamtest");
    Player->addCommands();
    set_this_player(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Player))
    {
        destruct(Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SafeSeamRequiresTheSurveyBeforeResolution()
{
    object quest = load_object(QuestPath);
    ExpectTrue(Player->beginQuest(QuestPath));
    ExpectFalse(quest->receiveEvent(Player, "readChapelRegister"));
    ExpectEq("started", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "inspectSpringWater"));
    ExpectEq("water measured", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "inspectCopperSeam"));
    ExpectEq("seam checked", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "inspectRoofSupports"));
    ExpectEq("supports checked", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "readChapelRegister"));
    ExpectEq("ready", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "keepSeamClosed"));
    ExpectEq("keep seam closed", Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void SafeSeamCanAuthorizeOnlyASupervisedSurfaceSurvey()
{
    object quest = load_object(QuestPath);
    ExpectTrue(Player->beginQuest(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "inspectSpringWater"));
    ExpectTrue(quest->receiveEvent(Player, "inspectCopperSeam"));
    ExpectTrue(quest->receiveEvent(Player, "inspectRoofSupports"));
    ExpectTrue(quest->receiveEvent(Player, "readChapelRegister"));
    ExpectTrue(quest->receiveEvent(Player, "allowLimitedSurvey"));
    ExpectEq("limited survey", Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void CopperOreRequiresTheSafeSeamQuestToBeCompleted()
{
    object quest = load_object(QuestPath);
    object feature = clone_object(
        "/areas/tol-dhurath/features/copper-seam.c");
    object environment = clone_object(
        "/lib/tests/support/environment/harvestRoom.c");
    object pickAxe = clone_object(
        "/lib/instances/items/weapons/hammers/pick-axe.c");

    move_object(Player, environment);
    move_object(pickAxe, Player);
    command("equip pick axe", Player);
    ExpectTrue(Player->isEquipped(pickAxe));
    feature->setUpForEnvironment("default", environment);

    ExpectFalse(feature->harvestResource("copper ore", Player, environment));

    ExpectTrue(Player->beginQuest(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "inspectSpringWater"));
    ExpectTrue(quest->receiveEvent(Player, "inspectCopperSeam"));
    ExpectTrue(quest->receiveEvent(Player, "inspectRoofSupports"));
    ExpectTrue(quest->receiveEvent(Player, "readChapelRegister"));
    ExpectFalse(feature->harvestResource("copper ore", Player, environment));
    ExpectTrue(quest->receiveEvent(Player, "keepSeamClosed"));
    ExpectTrue(Player->questIsCompleted(QuestPath));

    ExpectEq("/lib/instances/items/materials/metal-ores/copper.c",
        program_name(feature->harvestResource(
            "copper ore", Player, environment)));

    destruct(feature);
    destruct(environment);
}
