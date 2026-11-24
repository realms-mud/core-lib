//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Mera tests the grain with "
        "a thumb, then looks up from the millstone. @S@'If you "
        "have come to ask for flour, tell me whose grain you "
        "brought. If you have come to ask about the stream, "
        "that answer is longer.'");
    addTopic("the mill", "@D@She wipes flour from the edge of "
        "the hopper. @S@'This mill serves the farms on both sides "
        "of the ford. We grind in turns, and I keep the order "
        "on the board outside. A full sack means a household "
        "can make it through a wet week.'");
    addTopic("the stream", "@S@'The water feeds the wheel first, "
        "then the lower furrows. I open the side cut at dawn "
        "when the flow is good. No one gets to take all of it, "
        "not even the mill.'");
    addTopic("seed grain", "@D@Mera taps a narrow bin set apart "
        "from the mill sacks. @S@'That is next year's seed. "
        "It is not a reserve for hungry days, and it is not "
        "surplus. Grind it now and the whole village pays later.'");
    addTopic("your brother", "@S@'Renn is my younger brother. "
        "He can hear a loose bearing from the road and still "
        "forget where he put the wrench. I keep him because "
        "he notices what the rest of us walk past.'");
    addTopic("the toll", "@D@She glances toward the crown road. "
        "@S@'Loaded wagons pay by weight. Local carts carrying "
        "seed or a family's own harvest do not. If someone "
        "asks you for more, read the posted ledger and ask "
        "the sergeant to write down the difference.'");
    addTopic("the harvest", "@S@'The barley was cut early on "
        "the dry ridge and late beside the stream. We store "
        "each lot separately. Damp grain can spoil a bin "
        "before anyone notices the smell.'");

    addResponse("first conversation", "Can I use the mill?",
        "@D@Mera points to the queue board beside the door. "
        "@S@'Bring your own grain and put your name after "
        "the next marked household. I can show you the stones "
        "when the wheel is clear.'");
    addResponseTopic("first conversation", "Can I use the mill?",
        "the mill");
    addResponse("the mill", "How is the stream divided?",
        "@D@She traces the shallow channels with a floury finger. "
        "@S@'Wheel first while the flow is strong, then the "
        "lower furrows. If the water drops, I close the wheel "
        "and let the gardens drink.'");
    addResponseTopic("the mill", "How is the stream divided?",
        "the stream");
    addResponse("first conversation", "Can I take a sack of seed?",
        "@D@Mera closes the narrow bin and rests her hand on its lid. "
        "@S@'No. That grain belongs in next year's furrows. "
        "If a household needs food, ask at the common store; "
        "do not turn tomorrow's harvest into today's meal.'");
    addResponseTopic("first conversation", "Can I take a sack of seed?",
        "seed grain");
    addResponse("first conversation", "Who keeps the mill with you?",
        "@D@A smile tugs briefly at her mouth. @S@'Renn, mostly. "
        "He knows when a wheel sounds wrong, even if he cannot "
        "always tell you which part is making the noise.'");
    addResponseTopic("first conversation", "Who keeps the mill with you?",
        "your brother");
    addResponse("first conversation", "Is the toll fair?",
        "@D@She turns the posted rate sheet so you can read it. "
        "@S@'The amount is fair if it is the amount written "
        "there. The exemptions matter just as much. Keep your "
        "receipt and ask for the sergeant if the sums differ.'");
    addResponseTopic("first conversation", "Is the toll fair?",
        "the toll");
    addResponse("the harvest", "Why keep the grain lots apart?",
        "@D@Mera pinches a kernel and checks its dryness. "
        "@S@'The low fields held more rain. Mix them with the "
        "ridge grain and you risk spoiling both. Marking a "
        "sack takes a moment; losing a winter store takes months.'");
}
