//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the mantle", "@D@Galadhel takes a breath before "
        "answering. @S@'The Lord of Water says I must decide what "
        "to do with Celedrath's work. I do not feel ready to carry it.'");
    addTopic("choosing a teacher", "@S@'I could ask my mother, "
        "Morwen, or someone else to lead these lessons. I could "
        "also keep the work with me. None of those choices feels "
        "simple.'");
    addTopic("my lack of knowledge", "@D@She shakes her head. "
        "@S@'I know how to teach archery because I have spent "
        "years learning it. With this gift, I have more questions "
        "than answers.'");
    addTopic("the Lord's counsel", "@S@'He told me that failure "
        "can teach us, but that we cannot afford to fail at the "
        "wrong moment. I am still trying to understand how to "
        "hold both truths.'");
    addTopic("stepping forward", "@D@Galadhel looks toward the "
        "water. @S@'I may have to act before I feel ready. "
        "That does not mean I should act without listening.'");
    addTopic("asking for help", "@S@'I would ask Lord Kellgaard "
        "to guide us, but the Lord of Water says he would refuse. "
        "I must decide what I can do with the knowledge we have.'");

    addResponse("the mantle", "Why did he choose you?",
        "@S@'He believes I am the least entangled in the conflict "
        "and can see the group clearly. I am not certain that "
        "makes me the right person.'");
    addResponseTopic("the mantle", "Why did he choose you?",
        "choosing a teacher");
    addResponse("the mantle", "Will you accept the responsibility?",
        "@S@'I cannot answer yet. I need to understand what "
        "accepting it would ask of me and of the others.'");
    addResponseTopic("the mantle",
        "Will you accept the responsibility?", "my lack of knowledge");

    addResponse("choosing a teacher", "Why not ask your mother?",
        "@S@'I trust her judgment. But this cannot become her "
        "responsibility simply because I am afraid to carry it.'");
    addResponseTopic("choosing a teacher",
        "Why not ask your mother?", "asking for help");
    addResponse("choosing a teacher", "Could Morwen lead the lessons?",
        "@S@'She has her own duties and choices to make. I will "
        "not hand her another burden without asking what she wants.'");
    addResponseTopic("choosing a teacher",
        "Could Morwen lead the lessons?", "the mantle");

    addResponse("my lack of knowledge", "Then start by learning.",
        "@S@'That is what I intend to do. I must not confuse "
        "being unready with being unable to begin.'");
    addResponseTopic("my lack of knowledge",
        "Then start by learning.", "stepping forward");
    addResponse("the Lord's counsel", "How do you avoid failing at the wrong time?",
        "@S@'By knowing our limits, preparing together, and "
        "not treating urgency as permission to be careless.'");
    addResponseTopic("the Lord's counsel",
        "How do you avoid failing at the wrong time?", "stepping forward");
    addResponse("stepping forward", "What is the next step?",
        "@S@'I will speak with the others, hear what each of "
        "them needs, and make a choice we can all understand.'");
    addResponseTopic("stepping forward",
        "What is the next step?", "choosing a teacher");
    addResponse("asking for help", "Can you ask the group instead?",
        "@S@'Yes. I should not decide for them before I have "
        "even asked what they can contribute.'");
    addResponseTopic("asking for help",
        "Can you ask the group instead?", "stepping forward");
}
