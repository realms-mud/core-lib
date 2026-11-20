//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("his method", "@D@Halgaladh considers the notes "
        "carefully. @S@'Celedrath taught through exercises and "
        "mechanics. Vilias stressed focus. I believe the gift "
        "has patterns we can learn to recognize.'");
    addTopic("teaching the gift", "@S@'I want to understand "
        "this well enough to help the others use it. If we can "
        "find what works, we should be able to teach it.'");
    addTopic("peace and power", "@D@He turns the idea over in "
        "his mind. @S@'Miriel says the gift follows a person's "
        "own nature. I do not think that rules out a method; "
        "it means the method must fit the person.'");
    addTopic("learning from celedrath", "@S@'He corrected us "
        "when we were wrong, but he never made a lesson about "
        "shame. We learned more because we could keep trying.'");
    addTopic("working with galadhel", "@D@Halgaladh glances "
        "toward Galadhel. @S@'She and I approach problems in "
        "similar ways. We should compare what we notice without "
        "assuming the same answer will suit us both.'");

    addResponse("his method", "What makes you think there is a formula?",
        "@S@'The gift responds to focus and intention. If we "
        "observe carefully, we may find patterns in how it answers.'");
    addResponseTopic("his method",
        "What makes you think there is a formula?", "peace and power");
    addResponse("his method", "Could the method differ for each person?",
        "@S@'Yes. A shared principle can still take a different "
        "shape in each person's hands.'");
    addResponseTopic("his method",
        "Could the method differ for each person?", "teaching the gift");

    addResponse("peace and power", "What did Miriel mean by harmony?",
        "@S@'That a person's nature and the path they follow "
        "must agree. It may be difficult to measure, but it "
        "is worth paying attention to.'");
    addResponseTopic("peace and power",
        "What did Miriel mean by harmony?", "his method");
    addResponse("teaching the gift", "Are you ready to teach?",
        "@S@'Not yet. I must first be honest about what I "
        "understand and what I am only guessing.'");
    addResponseTopic("teaching the gift",
        "Are you ready to teach?", "learning from celedrath");

    addResponse("learning from celedrath", "What did he teach you best?",
        "@S@'To keep working after a failure, and to ask what "
        "the failure had shown us before trying again.'");
    addResponseTopic("learning from celedrath",
        "What did he teach you best?", "teaching the gift");
    addResponse("working with galadhel", "How will you compare notes?",
        "@S@'We can explain what we tried, what we felt, and "
        "what changed. We should leave room for a different result.'");
    addResponseTopic("working with galadhel",
        "How will you compare notes?", "his method");
}
