//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("vilias tale", "@D@Vilias looks past you, her voice "
        "quiet. @S@'There was a time when I helped others find "
        "courage, dream, and love. I called that work a song. "
        "I do not recognize the person who sings now.'");
    addTopic("what was stolen", "@S@'I trusted my heart once. "
        "It was broken, and I decided that feeling anything again "
        "was a weakness. Vengeance was easier to carry.'");
    addTopic("what remains", "@D@She studies her hands. @S@'The "
        "part of me that is ashamed has not disappeared. I do not "
        "know whether that is enough to change what I have become.'");
    addTopic("hope", "@S@'Hope is not a gift someone can force "
        "into another. It is a choice I once tried to help others "
        "make for themselves.'");
    addTopic("vengeance", "@D@Her gaze hardens. @S@'Vengeance "
        "gave my grief a direction. It did not give me peace, and "
        "it did not restore what I had lost.'");

    addResponse("vilias tale", "What were you before?",
        "@S@'I tried to bring harmony to those around me. I wanted "
        "them to be brave enough to love and to hope.'");
    addResponseTopic("vilias tale", "What were you before?",
        "what was stolen");
    addResponse("vilias tale", "You are more than your anger.",
        "@S@'Perhaps. I have not yet found the strength to believe it.'");
    addResponseTopic("vilias tale", "You are more than your anger.",
        "what remains");

    addResponse("what was stolen", "That does not excuse your choices.",
        "@S@'No. It explains them, perhaps. It does not excuse them.'");
    addResponseTopic("what was stolen",
        "That does not excuse your choices.", "what remains");
    addResponse("what was stolen", "Do you want to change?",
        "@S@'Wanting is the easy part. I have to choose differently "
        "when the moment comes.'");
    addResponseTopic("what was stolen", "Do you want to change?",
        "what remains");
    addResponse("what remains", "Then start with the next choice.",
        "@S@'I will try. That is all I can promise you.'");
    addResponse("what remains", "I will not trust you yet.",
        "@S@'You should not. Trust must be earned, not requested.'");
    addResponseTopic("what remains", "I will not trust you yet.",
        "what was stolen");
    addResponse("vilias tale", "What happened to your hope?",
        "@S@'I mistook pain for proof that hope had failed me. "
        "I chose anger because it asked less of me.'");
    addResponseTopic("vilias tale", "What happened to your hope?",
        "hope");
    addResponse("what was stolen", "Did vengeance help?",
        "@S@'It gave me something to do. It did not make the loss "
        "smaller or the choices right.'");
    addResponseTopic("what was stolen", "Did vengeance help?",
        "vengeance");
    addResponse("vengeance", "Can you let it go?",
        "@S@'Not all at once. I can refuse to let it choose for me "
        "the next time I am hurt.'");
    addResponseTopic("vengeance", "Can you let it go?", "what remains");
    addResponse("hope", "Can you bring that hope back?",
        "@S@'I do not know. I can begin by leaving room for others "
        "to choose it without my hand around their hearts.'");
    addResponseTopic("hope", "Can you bring that hope back?",
        "what remains");
}
