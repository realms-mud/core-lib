//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;
object Given;
object Requested;
object Room;

void Setup()
{
    Room = clone_object("/lib/environment/environment.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("alice");
    Player.Str(20);
    Player.Con(20);
    Player.Race("human");
    Player.addCommands();
    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target.Name("bob");
    Target.Str(20);
    Target.Con(20);
    Target.Race("human");
    Target.addCommands();
    move_object(Player, Room);
    move_object(Target, Room);
    Given = clone_object("/lib/items/item.c");
    Given.set("name", "apple");
    Given.set("value", 50);
    Given.set("weight", 1);
    Requested = clone_object("/lib/items/item.c");
    Requested.set("name", "book");
    Requested.set("value", 50);
    Requested.set("weight", 1);
    move_object(Given, Player);
    move_object(Requested, Target);
}

void CleanUp()
{
    if (objectp(Given))
    {
        destruct(Given);
    }
    if (objectp(Requested))
    {
        destruct(Requested);
    }
    destruct(Target);
    destruct(Player);
    destruct(Room);
}

void BarterRequiresAcceptanceAndRecordsBothDirectionsOnce()
{
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    ExpectEq(Player, environment(Given));
    ExpectEq(Target, environment(Requested));
    ExpectEq(0, Player.relationshipValue(Target, "trust"));
    ExpectFalse(Player.executeCommand("accept trade from alice"));
    ExpectTrue(Target.executeCommand("accept trade from alice"));
    ExpectEq(Target, environment(Given));
    ExpectEq(Player, environment(Requested));
    ExpectEq(2, Player.relationshipValue(Target, "trust"));
    ExpectEq(2, Target.relationshipValue(Player, "trust"));
    ExpectEq(1, Player.countObservations(([ "type":"trade.completed" ])));
    ExpectEq(1, Target.countObservations(([ "type":"trade.completed" ])));
    ExpectFalse(Target.executeCommand("accept trade from alice"));
    ExpectEq(2, Player.relationshipValue(Target, "trust"));
}

void DeclinedOrStaleOffersDoNotChangeInventoryOrRelationships()
{
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    ExpectTrue(Target.executeCommand("decline trade from alice"));
    ExpectFalse(Target.executeCommand("accept trade from alice"));
    ExpectEq(Player, environment(Given));
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    move_object(Requested, Room);
    ExpectFalse(Target.executeCommand("accept trade from alice"));
    ExpectEq(Player, environment(Given));
    ExpectEq(Room, environment(Requested));
    ExpectEq(0, Target.countObservations(([ "type":"trade.completed" ])));
}

void DefaultNpcAiAcceptsFairTradeAndRejectsUnfairOrEnemyOffers()
{
    destruct(Target);
    Target = clone_object("/lib/tests/support/relationships/npc.c");
    Target.Str(20);
    Target.Con(20);
    move_object(Target, Room);
    move_object(Requested, Target);
    Given.set("value", 1);
    ExpectFalse(Player.executeCommand("trade apple with chen for book"));
    ExpectEq(Player, environment(Given));
    Given.set("value", 50);
    Target.modifyRelationship(Player, "trust", -80);
    ExpectFalse(Player.executeCommand("trade apple with chen for book"));
    Target.setRelationshipValue(Player, "trust", 0);
    ExpectTrue(Player.executeCommand("trade apple with chen for book"));
    ExpectEq(Target, environment(Given));
    ExpectEq(Player, environment(Requested));
    ExpectEq(2, Target.relationshipValue(Player, "trust"));
}

void RejectedDropRollsBackBothSidesBeforeRelationshipEffects()
{
    destruct(Requested);
    Requested = clone_object(
        "/lib/tests/support/relationships/blocked-trade-item.c");
    move_object(Requested, Target);
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    ExpectFalse(Target.executeCommand("accept trade from alice"));
    ExpectEq(Player, environment(Given));
    ExpectEq(Target, environment(Requested));
    ExpectEq(0, Player.countObservations(([ "type":"trade.completed" ])));
}

void NonTransferableAndOverweightItemsCannotBeTraded()
{
    Given.set("undroppable", 1);
    ExpectFalse(Player.executeCommand("trade apple with bob for book"));
    Given.unset("undroppable");
    Requested.set("weight", 1000);
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    ExpectFalse(Target.executeCommand("accept trade from alice"));
    ExpectEq(Player, environment(Given));
    ExpectEq(Target, environment(Requested));
}

void TransferExceptionsAreExplicitAndRestoreBothInventories()
{
    destruct(Requested);
    Requested = clone_object(
        "/lib/tests/support/relationships/blocked-trade-item.c");
    Requested.testThrowOnDrop();
    move_object(Requested, Target);
    ExpectTrue(Player.executeCommand("trade apple with bob for book"));
    ExpectTrue(stringp(catch(load_object(
        "/lib/services/interpersonalTradingService.c")->acceptOffer(
            Target, Player); nolog)));
    ExpectEq(Player, environment(Given));
    ExpectEq(Target, environment(Requested));
    ExpectEq(0, Player.countObservations(([ "type":"trade.completed" ])));
    ExpectEq(0, Target.countObservations(([ "type":"trade.completed" ])));
}
