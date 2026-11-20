//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Torven levels a grain measure "
        "and writes its weight before acknowledging you. "
        "@S@'Stand clear of the moving gear. You can talk to me "
        "without putting a hand near the wheel.'");
    addTopic("the mill", "@S@'The stream does the turning; we do "
        "the lifting, sorting, and checking. Wet grain spoils in a "
        "closed sack. Nessa would rather hear about it today than "
        "find it in the granary next week.'");
    addTopic("the public crop", "@D@He sets the measure aside. "
        "@S@'Cross west from the loading yard, then west again "
        "for the gleaning strips. Those heads are left after the "
        "main harvest. They are not a license to empty the fields.'");
    addTopic("the old farm", "@S@'The deserted cellar is beyond "
        "the coppice, off the old cart track. The door still hangs "
        "on its straps, but the room is dark and the timbers have "
        "had too many wet winters. It is no longer a storehouse.'");
    addResponse("first conversation", "What keeps the mill working?",
        "@S@'Good water, dry grain, and someone noticing a bad "
        "bearing before the whole wheel tears at it.'");
    addResponseTopic("first conversation", "What keeps the mill working?",
        "the mill");
    addResponse("the mill", "Does every farm use this mill?",
        "@S@'The nearby households bring their grain here. "
        "Pera carries produce; Nessa keeps the shared stores.'");
    addResponse("first conversation", "Where may a traveler gather grain?",
        "@S@'Only in the marked gleaning strips, after harvest.'");
    addResponseTopic("first conversation",
        "Where may a traveler gather grain?", "the public crop");
    addResponse("the public crop", "Can I turn grain into flour here?",
        "@S@'These stones are working equipment, not a public "
        "bench. Ask Nessa for food you can carry as it is.'");
    addResponse("the mill", "What happens when the stream freezes?",
        "@S@'We use the stores and wait for a safe thaw. "
        "Nobody gains a meal by breaking the wheel on the ice.'");
    addResponse("first conversation", "Is there another store in the woods?",
        "@S@'There was. That is not the same as there being one now.'");
    addResponseTopic("first conversation",
        "Is there another store in the woods?", "the old farm");
    addResponse("the old farm", "Is the cellar a road north?",
        "@D@Torven taps the map margin. @S@'No. It ends at the "
        "old retaining wall. For Minlach take the coastal road "
        "and prepare for a long journey.'");
}
