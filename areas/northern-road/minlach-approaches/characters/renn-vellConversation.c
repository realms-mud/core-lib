//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Renn lays a wrench across "
        "the mill cart and wipes his hands on his trousers. "
        "@S@'If you are looking for the main road, it is behind "
        "you. If you are looking for the mill, Mera has the "
        "queue board and I have the tools.'");
    addTopic("the waterwheel", "@S@'The wheel turns best when "
        "the gate is half open. Too much water makes the boards "
        "kick; too little leaves the stones hungry. Mera can "
        "tell the difference by sound, which is annoying because "
        "she is always right.'");
    addTopic("your sister", "@D@He sets the wrench down with "
        "more care than his grin suggests. @S@'Mera has run "
        "the mill since our mother hurt her back. I look after "
        "the fields and the repairs. She says I am not allowed "
        "to fix things while they are moving.'");
    addTopic("the measure", "@S@'Every sack gets weighed before "
        "it goes near the stones. We write the household name "
        "and the weight where anyone in the queue can see it. "
        "A short measure makes enemies faster than a bad harvest.'");
    addTopic("the new road", "@D@Renn glances toward the long "
        "line of wagons. @S@'The road brings seed, tools, and "
        "people who have not slept enough. It also brings dust "
        "into every hinge in the village. We take the good "
        "with the grit.'");
    addTopic("the fields", "@S@'The north plots shed water well. "
        "The ones by the willow stand keep it too long after "
        "rain. I dug a second drain, but the lower furrows "
        "still need watching.'");
    addTopic("the drovers", "@S@'Vessa knows how to settle a "
        "nervous team. She will stop a whole train rather than "
        "push an animal onto a bad plank. The merchants call "
        "that slow. They also call her when a wheel breaks.'");

    addResponse("first conversation", "Who owns the mill?",
        "@D@Renn hooks the wrench back onto his belt. "
        "@S@'Mera and I keep it for the village. The stones "
        "belonged to our family, but the water and the queue "
        "serve everyone who works the surrounding plots.'");
    addResponseTopic("first conversation", "Who owns the mill?",
        "your sister");
    addResponse("first conversation", "Why weigh every sack?",
        "@D@He taps the board where the last tally is written. "
        "@S@'So a missing measure has a name and a date. We "
        "have had arguments over flour before; nobody wins "
        "when the numbers stay in one person's head.'");
    addResponseTopic("first conversation", "Why weigh every sack?",
        "the measure");
    addResponse("first conversation", "Can I adjust the wheel?",
        "@D@Renn steps between you and the moving gear. "
        "@S@'Not while it turns. Ask Mera to close the gate, "
        "then I can show you the bearing. I would rather lose "
        "an hour of grinding than a finger.'");
    addResponseTopic("first conversation", "Can I adjust the wheel?",
        "the waterwheel");
    addResponse("first conversation", "What grows in the fields?",
        "@D@He points toward the low plots beyond the willow. "
        "@S@'Barley on the ridge, roots in the kitchen beds, "
        "and pulses in the drier rows. The stream plots are "
        "useful, but they punish anyone who forgets the drains.'");
    addResponseTopic("first conversation", "What grows in the fields?",
        "the fields");
    addResponse("the new road", "Do you like the passing traffic?",
        "@D@Renn raises an eyebrow at the fresh ruts. "
        "@S@'I like the tools it brings. I like it less when "
        "a merchant leaves a broken axle in my lane and calls "
        "that a delivery.'");
    addResponse("first conversation", "Who can help with a wagon?",
        "@D@He nods toward the drover pens. @S@'Vessa can "
        "keep the animals calm while I look at the wheel. "
        "Do not unhitch a team unless she tells you to.'");
    addResponseTopic("first conversation", "Who can help with a wagon?",
        "the drovers");
}
