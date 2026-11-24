//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Vessa checks the knot on "
        "a lead rope before she answers. @S@'Give the animals "
        "room and they will give you room. Crowding them is how "
        "a quiet road turns into a broken cart.'");
    addTopic("the pens", "@S@'The west pen is for teams waiting "
        "on the road. The east side has water and a dry bed. "
        "Do not mix strange animals until they have had time "
        "to smell one another.'");
    addTopic("the south road", "@D@She studies the ruts before "
        "the gate. @S@'Minlach's market is where this train "
        "is headed. I take the high road in the wet season "
        "and the stream lane when the ground is firm.'");
    addTopic("the toll", "@S@'A loaded merchant wagon pays. "
        "A farmer carrying seed to the mill does not. If a "
        "watchman forgets the difference, ask him to check "
        "the board before anyone reaches for a purse.'");
    addTopic("the animals", "@D@Vessa rests her hand on the "
        "nearest yoke. @S@'Oxen do not care that a merchant "
        "promised to reach the market by noon. They care "
        "about footing, water, and whether the person at "
        "the lead is frightened.'");
    addTopic("the broken cart", "@S@'Renn has the tools to mend "
        "a wheel. I can keep a team steady while he works. "
        "If the load is shifting, unload it first. Pride "
        "does not hold a wagon upright.'");
    addTopic("your family", "@D@Her mouth softens, then settles "
        "back into its usual line. @S@'My mother kept a small "
        "team on the south farms. I learned to handle animals "
        "before I learned to read a road sign. She still says "
        "I am too quick to take the long route.'");

    addResponse("first conversation", "Can I walk through the pens?",
        "@D@Vessa lays the ash switch across the nearest gate. "
        "@S@'Use the public lane between the rails. Do not "
        "step behind a team or reach between the animals. "
        "If one starts to pull, stop and call me.'");
    addResponseTopic("first conversation", "Can I walk through the pens?",
        "the pens");
    addResponse("the pens", "Why keep the teams apart?",
        "@D@She checks a water bucket before replying. "
        "@S@'A strange team can spook another. Give them "
        "space, water, and a minute to settle. That is cheaper "
        "than replacing a harness.'");
    addResponse("first conversation", "How do I reach Minlach?",
        "@D@Vessa points along the broad, packed road. "
        "@S@'Keep to the main track and follow the wall signs. "
        "The smaller lane beside the stream is shorter, but "
        "it turns to mud after hard rain.'");
    addResponseTopic("first conversation", "How do I reach Minlach?",
        "the south road");
    addResponse("first conversation", "Do I need to pay a toll?",
        "@D@She points to the rate board by the keep. "
        "@S@'If you are leading a loaded trade wagon, yes. "
        "If you are a local carrying seed or your own crop, "
        "read the exemption list. It is there for a reason.'");
    addResponseTopic("first conversation", "Do I need to pay a toll?",
        "the toll");
    addResponse("the animals", "What makes a good drover?",
        "@D@Vessa slackens the lead rope until the team stops. "
        "@S@'Notice before you command. A tired animal gives "
        "warnings. People do too, if you bother to look.'");
    addResponse("first conversation", "Can you help with a broken cart?",
        "@D@She lifts the switch toward the mill yard. "
        "@S@'I can hold the team. Renn can look at the axle. "
        "Take the weight off the bad wheel before either of "
        "us starts working.'");
    addResponseTopic("first conversation", "Can you help with a broken cart?",
        "the broken cart");
    addResponse("your family", "Do you miss the south farms?",
        "@D@Vessa pulls the cap lower against the wind. "
        "@S@'I miss the people, not the mud. My mother still "
        "writes that the team walks straighter when I am there, "
        "which is not the same as asking me to come home.'");
}
