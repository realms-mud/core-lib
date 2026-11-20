//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the break", "@D@Galadhel looks toward the stream. "
        "@S@'I need air and room to think. If I stay in that "
        "room much longer, I will start mistaking frustration "
        "for useful work.'");
    addTopic("tinwen's silence", "@D@She glances toward the raven. "
        "@S@'I have asked Tinwen for help, but she keeps her "
        "counsel. Perhaps I am asking the wrong question.'");
    addTopic("the forest", "@S@'The woods are quiet enough to "
        "hear yourself think. That does not make the answers "
        "any clearer, but it can help you ask better questions.'");
    addTopic("duna's company", "@D@Galadhel's expression softens. "
        "@S@'Duna has duties to Morwen, yet she came with me. "
        "I appreciate that she did not make me explain myself first.'");
    addTopic("frustration", "@S@'I am used to being able to work "
        "at a problem until I find its shape. This one refuses "
        "to stay still long enough for that.'");

    addResponse("the break", "Do you want to be alone?",
        "@S@'Not entirely. I would like someone beside me who "
        "does not expect me to have an answer.'");
    addResponseTopic("the break", "Do you want to be alone?",
        "duna's company");
    addResponse("the break", "What are you hoping to find outside?",
        "@S@'Nothing specific. A little space may help me see "
        "what I have been too impatient to notice.'");
    addResponseTopic("the break",
        "What are you hoping to find outside?", "the forest");

    addResponse("tinwen's silence", "Perhaps she is waiting for you.",
        "@S@'Perhaps. I should not assume that silence means "
        "she has nothing to teach me.'");
    addResponseTopic("tinwen's silence",
        "Perhaps she is waiting for you.", "the forest");
    addResponse("tinwen's silence", "Will you ask her again?",
        "@S@'When I can ask without demanding that she solve "
        "the problem for me.'");
    addResponseTopic("tinwen's silence",
        "Will you ask her again?", "frustration");

    addResponse("frustration", "You can take more time.",
        "@S@'Time is exactly what I fear we do not have. Still, "
        "rushing without understanding may cost us more.'");
    addResponseTopic("frustration",
        "You can take more time.", "the break");
    addResponse("frustration", "You do not have to solve it alone.",
        "@S@'I know. I am learning that accepting help is "
        "different from giving up responsibility.'");
    addResponseTopic("frustration",
        "You do not have to solve it alone.", "duna's company");
    addResponse("duna's company", "Does she understand your worry?",
        "@S@'She has her own burden. She need not share mine "
        "exactly to understand that I am struggling.'");
    addResponseTopic("duna's company",
        "Does she understand your worry?", "the break");
}
