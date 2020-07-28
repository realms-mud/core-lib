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
        "certainly dressed the part. I am Maiwyn. I must have been "
        "captured a very long time indeed, for the Aegis Guard I "
        "remember would not think so little of their mission and the kingdom "
        "they serve so as to hide their identity. No matter. I shan't pry. "
        "As for what's going on here...' "
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addResponseTopic("first conversation", "I am an agent of the king...", 
        "gave title");
    addResponse("gave title", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. Apologies, "
        "but discretion seemed the wisest course.'");
    addResponse("gave title", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("was rude", "@D@She smirks and dryly replies, @S@'Say not that "
        "chivalry is dead in the Aegis Guard. Aye, I know what you are "
        "and that is enough for my request. I am Maiwyn and as for what "
        "has happened here...'"
        "@D@Maiwyn takes a ragged breath and appears to be making a valiant "
        "effort to hold back tears. @S@'I do not know much, but it feels like a "
        "lifetime ago... ");
    addResponseTopic("first conversation", "No, who are you?",
        "was rude");
    addResponse("was rude", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. Apologies, "
        "but discretion seemed the wisest course.'");
    addResponse("was rude", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("gave name second chance", "@D@She smiles warmly and says, "
        "@S@'Well met, ##ActorName##. There is wisdom in caution...");
    addResponseTopic("gave title", "I am...", "gave name second chance");
    addResponseTopic("was rude", "I am...", "gave name second chance");
    addTopicEvent("gave name second chance", "playerGaveName");
    addResponse("gave name second chance", "@I@Continue@E@", "@I@Continue@E@");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynStoryPartOne()
{
    addTopic("story part one", "@S@'I was waylaid on my way from Eledhel to "
        "my family's estate in Ethyl Tirath...' @D@Maiwyn appears to be "
        "doing some mental gymnastics and then asks, @S@'What year is it?'");
    addResponseTopic("gave name second chance", "@I@Continue@E@", 
        "story part one");
    addResponseTopic("gave name", "@I@Continue@E@", "story part one");
    addResponseTopic("gave title", "@I@Continue@E@", "story part one");
    addResponseTopic("was rude", "@I@Continue@E@", "story part one");

    addResponse("story part one", "It is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'It is "
        "##CallOther::getDateAndTime##.'");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynStoryPartTwo()
{
    addTopic("story part two", "@S@'You cannot be serious! I have been "
        "here for eight years then. They have stolen so much of my life..."
        "' @D@Maiwyn trails off, deep in contemplation. @S@'I and a dozen "
        "others have been held here... over the years, many have been "
        "killed, many... abused. The periods of simple neglect are the "
        "best. I would say a good two score of these outlaws live in "
        "this ruin, though many are constantly coming and going.'");
    addResponseTopic("story part one", "It is...", "story part two");

    addResponse("story part two", "Your escape...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::look## at Maiwyn and "
        "##ResponseInfinitive::ask##, @S@'How did you escape your captors?'");
    addResponse("story part two", "About these outlaws...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@'What can you tell me about these "
        "outlaws? What are they doing here?'");
    addResponse("story part two", "This ruin...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'I know that Tol-Dhurath was once "
        "a fastness of the Scions of Dhuras and were built to commemorate "
        "the defeat the invading armies of the Kingdom of Andurath at this "
        "very site. What can you tell me of its more recent uses?'");
    addResponse("story part two", "The other captives...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::inquire##, @S@'You "
        "mentioned other captives. What can you tell me of them?'");
    addResponse("story part two", "What did they do to you?", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'What "
        "have you done here these last eight years? What did they do to "
        "you?'");
    addResponse("story part two", "Assistance @I@Quest@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'The crimes committed here cannot "
        "go unanswered. You know the lay of this place. Tell me where the "
        "enemy can be found and where the others prisoners are held.'");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    MaiwynIntroduced();
    MaiwynStoryPartOne();
    MaiwynStoryPartTwo();
}
