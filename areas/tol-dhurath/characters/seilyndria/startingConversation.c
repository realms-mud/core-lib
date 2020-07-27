//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void MaiwynIntroduced()
{
    addTopic("first conversation", "@D@A rather surprised-looking woman "
        "dressed in a dirty tan-ish shirt and equally dirty pants stands "
        "before you. Her garments are both made of coarse, thread-bare linen "
        "and show signs of excessive mistreatment. There are many stains - "
        "some of blood and some of what appear to be porridge. She smells of "
        "sweat, urine, feces, and rotting food. Her auburn hair is disheveled "
        "and rather filthy. Dirt, bruises, and abrasions mark her face. "
        "All of the abuse and neglect does not obscure the fact that she "
        "is an incredibly attractive woman. Her pale blue eyes open a window "
        "into a tortured, despairing soul. She shakily, but menacingly, "
        "snarls @S@'Nay! Nay, I will not go back!' @D@She raises her arm "
        "behind her head, a rock in her hand. She pauses in confusion, "
        "@S@'Wait. You are not my tormentors. Who are you?'");

    addResponse("first conversation", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. You need not "
        "fear me. What is going on here?");

    addResponse("first conversation", "I am an agent of the king...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'I am here by the authority of "
        "King Ardenel of Eledhel, my lady. How may I be of service?'");

    addResponse("first conversation", "No, who are you?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'Nay my lady, who are you and what "
        "has happened here?");

    addTopic("gave name", "@D@She smiles warmly and says, @S@'Well met, "
        "##ActorName##. I am Maiwyn. As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addTopicEvent("gave name", "playerGaveName");
    addResponseTopic("first conversation", "I am...", "gave name");
    addResponse("gave name", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("gave title", "@D@She smirks slightly and says, @S@'Well, you're "
        "certainly dressed the part. I am Maiwyn of House Belectar. I must "
        "have been captured a very long time indeed, for the Aegis Guard I "
        "remember would not think so little of their mission and the kingdom "
        "they serve so as to hide their identity. There is As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addResponseTopic("first conversation", "I am an agent of the king...", 
        "gave title");
    addResponse("gave title", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("was rude", "@D@She smiles warmly and says, @S@'Well met, "
        "##ActorName##. I am Maiwyn. As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addResponseTopic("first conversation", "No, who are you?",
        "was rude");
    addResponse("was rude", "@I@Continue@E@", "@I@Continue@E@");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    MaiwynIntroduced();
}
