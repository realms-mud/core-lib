//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Hedran closes the ledger with "
        "one finger holding his place. @S@'If you came north with a "
        "cart, tell me whether its axle is sound before you tell me "
        "what is in it. The road takes a poor inventory.'");
    addTopic("the stores", "@S@'The flour is marked for the watch, "
        "the salt for the coast, and the lamp oil for the signal "
        "stations. A sack in the wrong place is not always theft. "
        "Sometimes the river changes who can reach it.'");
    addTopic("the signal chain", "@D@He turns the ledger around and "
        "draws a row of small circles. @S@'The ridge beacon answers "
        "the southern post, then the high watch. If one goes dark, "
        "the next keeper repeats the last clear mark. Never invent "
        "a message to fill a silence.'");
    addTopic("the winter road", "@S@'The snow is not the worst part. "
        "It hides the places where the stream undercuts the track. "
        "I shut the northern route when the ford stones disappear, "
        "even if a merchant swears his team can manage.'");
    addTopic("the old post", "@D@Hedran rubs a pale line in the "
        "wooden counter. @S@'Before Phaedra came, this was a "
        "charcoal stop with a roof and no walls. My mother served "
        "the first garrison stew in a cooking pot with a crack "
        "through the bottom. We still use it for nails.'");
    addTopic("your ledger", "@D@He touches the scar at his brow. "
        "@S@'I used to ride supply with the southern wagons. One "
        "winter a driver swore he had delivered every sack. The "
        "patrol had no flour by the fifth day. I started counting "
        "for myself after that. It is not a grand duty, but it "
        "keeps people fed.'");

    addResponse("first conversation", "What supplies can travelers get?",
        "@D@Hedran marks a line in the ledger before answering. "
        "@S@'Mira at the inn sells a hot meal when she has one to "
        "spare. The outpost stores are assigned to the patrol; I "
        "will not take food from a soldier's ration.'");
    addResponseTopic("first conversation",
        "What supplies can travelers get?", "the stores");
    addResponse("the stores", "Why are some flour sacks marked in blue?",
        "@D@He turns the ledger to a page marked with blue ink. "
        "@S@'Mill stock for the north watch. The blue thread means "
        "it was weighed at Hollow Mill, not that it is free to take.'");
    addResponse("first conversation", "What does the beacon mean?",
        "@D@Hedran points to the ridge beyond the palisade. "
        "@S@'The fire speaks in patterns. Ask Nerys before you "
        "touch anything; a well-meant signal can send riders the "
        "wrong way.'");
    addResponseTopic("first conversation", "What does the beacon mean?",
        "the signal chain");
    addResponse("the signal chain", "What if the ridge beacon is dark?",
        "@D@He draws a short line through the last circle in the chain. "
        "@S@'Wait for the next post to answer, then report the gap. "
        "A missing answer is useful information. A guessed answer "
        "is a danger.'");
    addResponse("first conversation", "Can I travel north in winter?",
        "@D@Hedran taps the map where the road meets the river. "
        "@S@'Ask the sentry and look at the ford markers. The "
        "decision depends on water and ice, not the date.'");
    addResponseTopic("first conversation",
        "Can I travel north in winter?", "the winter road");
    addResponse("first conversation", "How long have you been here?",
        "@D@He glances up at the patched rafters. "
        "@S@'Long enough to know which roof leaks before the rain. "
        "The post was smaller when my mother worked it.'");
    addResponseTopic("first conversation",
        "How long have you been here?", "the old post");
    addResponse("the old post", "Do you ever miss riding the wagons?",
        "@D@Hedran closes the ledger and rests a hand on its cover. "
        "@S@'I miss the people, "
        "not the road at night. A list can be checked in daylight.'");
    addResponse("your ledger", "Did you catch the missing driver?",
        "@D@He rubs the pale scar at his brow. "
        "@S@'No. The sacks had gone before he took the contract. "
        "That is why I ask questions before I decide who is guilty.'");
}
