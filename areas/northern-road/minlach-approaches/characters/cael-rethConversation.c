//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Cael finishes a line on "
        "his slate before giving you his attention. @S@'The "
        "road is open. The rules are posted. If either is "
        "unclear, ask before you move a wagon through the gate.'");
    addTopic("the toll ledger", "@S@'The toll pays for road "
        "repairs and the watch. The weight, rate, and exemption "
        "are written in the open ledger. I will not collect "
        "an amount I cannot show you there.'");
    addTopic("the patrol", "@D@He marks a short line on the "
        "watch slate. @S@'Two patrols walk the road at different "
        "hours. We check the stream crossings, the pens, and "
        "the hill track. We are here to prevent trouble, not "
        "to charge every traveler with it.'");
    addTopic("the crown keep", "@S@'This post holds the road "
        "for the crown. We keep the toll record, inspect the "
        "crossing, and shelter the patrol when the weather "
        "turns. It is not a private estate and it has no lord.'");
    addTopic("the exemptions", "@D@Cael taps the lower half "
        "of the rate board. @S@'Seed grain, household harvest, "
        "and aid loads for the common store are exempt. Trade "
        "goods are not. If a load is mixed, we weigh the parts "
        "separately rather than guess.'");
    addTopic("the hill", "@S@'The old frame on the hill is "
        "not an active punishment post. The watch uses the "
        "track to look over the road. The names on its stone "
        "are for two patrolmen lost in a storm, not a sentence.'");
    addTopic("your duty", "@D@He rubs chalk from one thumb. "
        "@S@'I took this post after a winter escort went wrong. "
        "I had the route on paper and forgot to ask the people "
        "who used it every day. I do not make that mistake twice.'");

    addResponse("first conversation", "How much is the toll?",
        "@D@Cael points to the open ledger on the stone shelf. "
        "@S@'It depends on the weight and kind of cargo. The "
        "rates are there, along with the exemptions. Read them "
        "before you pay.'");
    addResponseTopic("first conversation", "How much is the toll?",
        "the toll ledger");
    addResponse("the toll ledger", "What if the amount is wrong?",
        "@D@He sets the chalk beside the book. @S@'Ask me to "
        "weigh the load again, and keep the first receipt. "
        "If I made the error, I correct the entry in front "
        "of you.'");
    addResponse("first conversation", "Are the roads dangerous?",
        "@D@Cael studies the slate before answering. "
        "@S@'Most days the danger is weather, a bad wheel, "
        "or a frightened team. We patrol the hill track too. "
        "A warning is not proof that someone is guilty.'");
    addResponseTopic("first conversation", "Are the roads dangerous?",
        "the patrol");
    addResponse("first conversation", "Who owns the keep?",
        "@D@He rests his hand on the post's crown-marked sign. "
        "@S@'The crown holds it as a public road post. The "
        "watch is responsible for it; no family collects "
        "the toll for itself.'");
    addResponseTopic("first conversation", "Who owns the keep?",
        "the crown keep");
    addResponse("first conversation", "Which loads are exempt?",
        "@D@Cael turns the rate board toward you. @S@'Seed, "
        "a family's own harvest, and common-store aid. Bring "
        "the goods forward separately and I will record them "
        "as they are.'");
    addResponseTopic("first conversation", "Which loads are exempt?",
        "the exemptions");
    addResponse("first conversation", "What is on the hill?",
        "@D@He looks beyond the road wall toward the bare rise. "
        "@S@'An old frame, a lookout, and a memorial stone. "
        "It is not a place to camp. The track is narrow and "
        "the brush hides the edge.'");
    addResponseTopic("first conversation", "What is on the hill?",
        "the hill");
    addResponse("your duty", "Do you trust the people on this road?",
        "@D@Cael puts away the slate and meets your eyes. "
        "@S@'I trust what I can verify. I listen to people "
        "before I decide what their evidence means.'");
}
