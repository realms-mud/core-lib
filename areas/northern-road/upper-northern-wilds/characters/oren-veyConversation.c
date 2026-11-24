//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Oren waits for the wheel to "
        "complete a turn before he answers. @S@'Do not stand between "
        "the gear and the wall. It is old enough to have opinions "
        "and heavy enough to make them final.'");
    addTopic("the mill", "@S@'The Hollow takes grain from the "
        "hamlets on both sides of the ridge. I weigh the sacks "
        "before the stones and the flour after. That way a "
        "shortage has a name and a date, not just another "
        "argument.'");
    addTopic("the broken wheel", "@D@Oren listens, head tilted, "
        "to the slow knock in the frame. @S@'The wheel is sound. "
        "The bearing is not. My daughter says it knocks like a "
        "woodpecker. She is right, but the bearing was already "
        "bad before she was born.'");
    addTopic("the river", "@S@'The mill race is shallow in summer "
        "and mean in spring. The old bridge upstream used to take "
        "the carts. Now the ford is the only crossing I trust. "
        "If the stones vanish under water, wait.'");
    addTopic("the missing sacks", "@S@'Two flour sacks went from "
        "the store last month. They returned three days later, "
        "lighter and marked with a different seal. I know who "
        "took them. I do not know who was hungry.'");
    addTopic("the cellar", "@D@He keeps his eyes on the wheel. "
        "@S@'There is an old hatch below the millstone. I did not "
        "build it, and I did not invite anyone to use it. If you "
        "find the ring, pull it once and wait for the stone to "
        "settle before you go down.'");
    addTopic("your daughter", "@S@'She is at the southern farms "
        "with her mother. She sends me carved beads and asks "
        "whether the mill can grind apples. It cannot. I keep "
        "answering as if the question might change.'");

    addResponse("first conversation", "What is wrong with the wheel?",
        "@D@Oren wipes a streak of grease from the bearing housing. "
        "@S@'A bearing is wearing through. It can turn for now, "
        "but I will not run it hard until I have the new iron.'");
    addResponseTopic("first conversation", "What is wrong with the wheel?",
        "the broken wheel");
    addResponse("the broken wheel", "Why not stop the mill entirely?",
        "@D@He listens to the wheel's uneven knock. "
        "@S@'Because the households would lose their flour this "
        "week. I keep the load light and the watch on the axle.'");
    addResponse("first conversation", "Can I cross the river here?",
        "@D@Oren points away from the fast water under the wheel. "
        "@S@'Not through the wheel race. Use the marked ford "
        "below the broken bridge, and turn back if the water "
        "covers the pale stones.'");
    addResponseTopic("first conversation",
        "Can I cross the river here?", "the river");
    addResponse("first conversation", "Who took the flour?",
        "@D@Oren sets his jaw, then lets the tension ease. "
        "@S@'People who were keeping warm in a cellar. That does "
        "not make the flour theirs. It does make the answer "
        "harder than a rope and a pair of cuffs.'");
    addResponseTopic("first conversation", "Who took the flour?",
        "the missing sacks");
    addResponse("the missing sacks", "Should I tell the outpost?",
        "@D@He pulls the sack tally from beneath the ledger. "
        "@S@'Hedran will ask what was taken and who went without. "
        "Take him the marked sack tally, not a rumor.'");
    addResponse("first conversation", "How do I find the cellar?",
        "@D@Oren glances toward the wheel room and lowers his voice. "
        "@S@'Look beneath the dust at the wheel room floor. The "
        "iron ring lifts the stone. I am asking you not to start "
        "a fight in the mill.'");
    addResponseTopic("first conversation", "How do I find the cellar?",
        "the cellar");
    addResponse("the cellar", "Why have you not sealed the hatch?",
        "@D@He presses his palm against the old stone floor. "
        "@S@'The stone predates my family. If I seal it, someone "
        "will break it open. I would rather know who is below.'");
    addResponse("first conversation", "What does your daughter make?",
        "@D@Oren turns a small bead between his fingers. "
        "@S@'Small wooden beads, each one carved a little better "
        "than the last. She sends them up the road with the grain "
        "cart.'");
    addResponseTopic("first conversation", "What does your daughter make?",
        "your daughter");
}
