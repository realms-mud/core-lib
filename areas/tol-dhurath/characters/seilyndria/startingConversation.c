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
    addTopicEvent("gave name", "revealName");
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
    addTopicEvent("gave title", "revealName");
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
    addTopicEvent("was rude", "revealName");
    addResponseTopic("first conversation", "No, who are you?",
        "was rude");
    addResponse("was rude", "I am...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'I am ##ActorName##. Apologies, "
        "but discretion seemed the wisest course.'");
    addResponse("was rude", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("gave name second chance", "@D@She smiles warmly and says, "
        "@S@'Well met, ##ActorName##. There is wisdom in caution... I "
        "am honored that you have chosen to trust me with your name.");
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
        "others have been held here... over the years, many others have been "
        "killed, many... abused. The periods of simple neglect are the "
        "best. I would say a good score or so of these outlaws are in "
        "this ruin at any given time, though many more are constantly "
        "coming and going.'");
    addResponseTopic("story part one", "It is...", "story part two");

    addResponse("story part two", "Your escape...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::look## at Maiwyn and "
        "##ResponseInfinitive::ask##, @S@'How did you escape your captors?'");
    addResponse("story part two", "About these outlaws...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@'What can you tell me about these "
        "outlaws? What are they doing here?'");
    addResponse("story part two", "This ruin...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::note##, @S@'I know that this ruin was once a "
        "fastness of the Scions of Dhuras. What can you tell me of its more "
        "recent uses?'");
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
private void MaiwynDiscussionEscape()
{
    addTopic("my escape", "@S@'It was one of the outlaw's...' @D@Maiwyn's "
        "face flashes a hint of pain that is quickly sealed behind a wall. "
        "She continues levelly, @S@'time to be with me. He threw me down "
        "and I was fortunate enough to find this rock. After I killed him, "
        "I fled his alcove and met up with you as I was about to leave "
        "this place. I know that it looks like I am running to save only "
        "myself, but please believe me - I was going to report this as "
        "soon as I got to safety. You being here opened up another "
        "possibility.'");
    addResponseTopic("story part two", "Your escape...", "my escape");
    addResponse("my escape", "@I@Continue@E@", "@I@Continue@E@");
    addResponseTopic("my escape", "@I@Continue@E@", "story part two");
}

/////////////////////////////////////////////////////////////////////////////
private void MaiwynDiscussionOutlaws()
{
    addTopic("the outlaws", "@S@'They are brutal and efficient. They're "
        "led by a man known as \"Lord Sullath\". In all the time I have "
        "been here, I've seen him but a couple times. He does not pay "
        "any attention to us prisoners, but he exudes a darkness about "
        "himself.' @D@Maiwyn shudders at this and then continues. @S@'"
        "When I first met him, he stated that he has set himself to "
        "seize control of Eledhel. He practically swooned as he mentioned "
        "his devoted worship of his mistress - one he calls Seilyndria...");

    addTopicInterjection("the outlaws",
        "/areas/tol-dhurath/characters/galadhel/galadhel.c",
        "seilyndria", 1);
    addResponseTopic("story part two", "About these outlaws...", "the outlaws");

    addResponse("the outlaws", "Did you say Seilyndria? @A@Theology@E@",
        "@S@'Did you say Seilyndria? As in the Goddess of Destruction?' "
        "@C@##InitiatorName## ##ResponseInfinitive::trail## off, "
        "seemingly deep in thought.");
    addResponsePrerequisite("the outlaws",
        "Did you say Seilyndria? @A@Theology@E@",
        (["theology":(["type":"skill", "value" : 1])]), 1);

    addResponse("the outlaws", "Galadhel?",
        "@S@'You are familiar with this Seilyndria, Galadhel?' @D@"
        "@C@##InitiatorName## ##ResponseInfinitive::ask## in a troubled "
        "voice.");
    addResponsePrerequisite("the outlaws", "Galadhel?",
        (["presence":(["type":"presence", "value" : ({ "galadhel" })])]));

    addResponse("the outlaws", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("outlaws - seilyndria", "@D@Maiwyn's face is very difficult "
        "to read. She bites down on her lip before interjecting, @S@'"
        "Lord Sullath told me a tale, about why he has taken this place "
        "for his own. It was built by the Scions of Dhuras on the site "
        "where Queen Bryleth the Vain of Andurath was defeated and "
        "captured.' @D@Maiwyn looks a little skeptical as she continues, "
        "@S@'Lord Sullath claims that Bryleth was actually Seilyndria "
        "and he chose this place to honor her as he carries out his "
        "work. He gave us two options: go through the Trial of Obedience "
        "and join his cause or serve his cause in death.'");
    addResponseTopic("the outlaws", "Did you say Seilyndria? @A@Theology@E@", 
        "outlaws - seilyndria");
    addResponseTopic("the outlaws", "Galadhel?",
        "outlaws - seilyndria");

    addResponse("outlaws - seilyndria", "And yet you live...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::state##, @S@'And here you are. "
        "Alive...'");
    addResponse("outlaws - seilyndria", "Did you join him?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::say##, @S@'How do you come to be "
        "here? I want to believe that you didn't join him, but you are "
        "here, very much alive.'");
    addResponse("outlaws - seilyndria", "His cause...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Maiwyn "
        "and ##ResponseInfinitive::ask##, @S@'You said he wishes to "
        "seize control of Eledhel. Do you know how?'");

    addTopic("maiwyn offended", "@D@Maiwyn erupts into tears. She "
        "angrily wipes them away and snarls, @S@'How dare you!? I only "
        "wish that these bastards had killed me! Those wretched monsters "
        "kill all the men they capture. The women, they find other uses "
        "for!' @D@She glares at ##InitiatorName## most unfriendily and "
        "suggests that ##InitiatorSubjective## do something that "
        "##InitiatorSubjective## ##ResponseInfinitive::be## anatomically "
        "ill-equipped to do.");
    addResponseTopic("outlaws - seilyndria", "And yet you live...",
        "maiwyn offended");
    addResponseTopic("outlaws - seilyndria", "Did you join him?",
        "maiwyn offended");

    addTopicInterjection("maiwyn offended",
        "/areas/tol-dhurath/characters/galadhel/galadhel.c",
        "maiwyn offended", 1);
    addResponse("maiwyn offended", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("seizing eledhel", "@D@Maiwyn sighs and forces herself to "
        "move forward with her conversation. @S@'I know only that they "
        "are raising an army. I do not know where, how many, how "
        "organized, how anything! I am simply their plaything and not "
        "considered human enough to discuss such things with.'");
    addResponseTopic("maiwyn offended", "@I@Continue@E@",
        "seizing eledhel");
    addResponseTopic("outlaws - seilyndria", "His cause...",
        "seizing eledhel");
    addResponseTopic("the outlaws", "@I@Continue@E@", "seizing eledhel");

    addResponse("seizing eledhel", "@I@Continue@E@", "@I@Continue@E@");

    addResponseTopic("seizing eledhel", "@I@Continue@E@", "story part two");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    MaiwynIntroduced();
    MaiwynStoryPartOne();
    MaiwynStoryPartTwo();
    MaiwynDiscussionEscape();
    MaiwynDiscussionOutlaws();
}
