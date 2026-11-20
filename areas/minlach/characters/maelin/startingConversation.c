//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Maelin brushes a shaving "
        "from his sleeve. @S@'The common hedge is not the timber "
        "plot. People keep forgetting which permission applies where.'");
    addTopic("woods briefing", "@S@'A tenant gathered berries "
        "and cut wood. Those are separate acts on separate ground. "
        "I need the boundary checked before either is judged.'");
    addTopic("woods route", "@S@'Investigate the boundary stone "
        "west on the old road, the timber cuts north of it, "
        "then the tenant fuel permit here at the lodge.'");
    addTopic("woods accepted", "@D@Maelin opens his permit folder. "
        "@S@'Read the actual grant. A berry basket is not a logging license.'");
    addTopicEvent("woods accepted", "minlachBeginWoods");
    addTopic("woods finding", "@S@'Fallen fuel allowed, standing "
        "timber not allowed. And the berries came from the common. "
        "We can address the cut without forbidding lawful forage.'");
    addTopic("woods costs mediated", "@D@Maelin sets out a "
        "compensation sheet. @S@'A limited repair of the damage, "
        "and the common stays open.'");
    addTopicEvent("woods costs mediated", "mediateWoodlandCosts");
    addTopic("woods boundary recorded", "@S@'I will record the "
        "timber violation and the lawful gathering separately.'");
    addTopicEvent("woods boundary recorded", "recordWoodlandBoundary");
    addResponse("first conversation", "Is someone accused of poaching?",
        "@D@You ask about the disputed permit.");
    addResponseTopic("first conversation", "Is someone accused of poaching?",
        "woods briefing");
    addResponse("woods briefing", "Where is the boundary?",
        "@D@You ask which ground each permission covers.");
    addResponseTopic("woods briefing", "Where is the boundary?", "woods route");
    addResponse("woods briefing", "Why not forbid all gathering?",
        "@S@'Because a managed plot is not the whole woodland. "
        "Punishing neighbors for lawful forage would solve nothing.'");
    addResponseTopic("woods briefing", "Why not forbid all gathering?",
        "woods route");
    addResponse("woods route", "I will check the boundary and permit.",
        "@D@You agree to separate gathering from timber cutting.");
    addResponseTopic("woods route", "I will check the boundary and permit.",
        "woods accepted");
    addResponse("woods route", "I will come back later.",
        "@D@Maelin closes the folder, leaving the marker map visible.");
    addResponse("first conversation", "I checked the woodland rights.",
        "@D@You report the common boundary, fresh cuts, and limited permit.");
    gateQuestResponse("first conversation", "I checked the woodland rights.",
        "woodland-boundary", "ready");
    addResponseTopic("first conversation", "I checked the woodland rights.",
        "woods finding");
    addResponse("woods finding", "Mediate fair compensation.",
        "@D@You recommend repairing the damage without closing the common.");
    addResponseTopic("woods finding", "Mediate fair compensation.",
        "woods costs mediated");
    addResponse("woods finding", "Record the two acts separately.",
        "@D@You ask for a precise boundary and violation record.");
    addResponseTopic("woods finding", "Record the two acts separately.",
        "woods boundary recorded");
}
