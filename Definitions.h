#pragma once

//Screen size
#define SCREEN_WIDTH 864
#define SCREEN_HEIGHT 632

//Egg information
#define NUMBER_EGG 4
#define EGG_WIDTH 64
#define EGG_HEIGHT 82
#define EGG_Y_POSTION 470

//Heart information
#define HEART_WIDTH 64
#define HEART_DIST_PET 6
//heart folder
#define HEART "graphics/Pet/Heart/"

//Toybox corner points
#define TOYBOX_LEFT_X 441
#define TOYBOX_RIGHT_X 533
#define TOYBOX_LEFT_Y 281
#define TOYBOX_RIGHT_Y 382

//Needs information
#define MAX_NEEDS 5
#define NEED_ICON_SIZE 65
#define NEED_SCALE_FRAMES 11
#define NEEDS_CIRCLE_DISTANCE 0.2
//Need scale folder
#define NEED_SCALE "graphics/Needs/"

//Title files
#define LOGO "graphics/Titles/logo.png"
#define WIN_TITLE "graphics/Titles/youWin.png"
#define LOOSE_TITLE "graphics/Titles/gameOver.png"
#define ROOM_TITLE "graphics/Titles/"

//Backgrounds files
#define ROOM_BACKGROUND "graphics/Backgrounds/room.png"
#define YARD_BACKGROUND "graphics/Backgrounds/yard.png"
#define CLASS_BACKGROUND "graphics/Backgrounds/speak.png"
#define CANDY_WINDOW "graphics/Backgrounds/candy.png"
#define MENU_WINDOW "graphics/Backgrounds/menu.png"

//Sounds folders
#define BACKGROUND_SOUND "sounds/Background/"
#define GAME_SOUND "sounds/Game/"
#define ACTION_SOUND "sounds/Action/"
#define SPEAK_SOUNDS "sounds/Words/Speak/"
#define LEARN_SOUND "sounds/Words/Learn/"

//Buttons files
#define BIG_PLAY_BUTTON "graphics/Buttons/play.png"
#define BACK_BUTTON "graphics/Buttons/back.png"
#define PAUSE_BUTTON "graphics/Buttons/pause.png"
#define SOUND_ON "graphics/Buttons/SoundOn.png"
#define SOUND_OFF "graphics/Buttons/SoundOff.png"
#define SPEAK_BUTTON "graphics/Buttons/speak.png"
#define LOCKED_WORD "graphics/Buttons/word_block.png"
#define UNLOCKED_WORD "graphics/Buttons/word.png"
#define LEARNING_WORD "graphics/Buttons/word_learned.png"

//Accessorises information
#define ACCESSORIES_NUBER 4
//Accessorises files
#define REFRIGERATOR "graphics/Accessories/refrigerator.png"
#define BED "graphics/Accessories/bed.png"
#define BATH "graphics/Accessories/bath.png"
#define TABLE "graphics/Accessories/table.png"
#define OPENED_REFRIGERATOR "graphics/Accessories/openFridge.png"
#define USED_BED "graphics/Accessories/bedSleep.png"

//Pam files
#define HAPPY_PAM_WINDOW "graphics/Pam/happyPam.png"
#define SAD_PAM_WINDOW "graphics/Pam/sadPam.png"
#define SMALL_PAM_WINDOW "graphics/Pam/pamSmall.png"

//Pet folders
#define COCO "graphics/Pet/Fox/"
#define FIFI "graphics/Pet/Penguin/"
#define BOO "graphics/Pet/Pug/"
#define ANGEL "graphics/Pet/Bunny/"

//Effect folders
#define BATH_ANIMATION "graphics/Effects/Water/bath"
#define SLEEP_ANIMATION "graphics/Effects/Sleep/"
#define BEING_PET_ANIMATION "graphics/Effects/Pet/"
#define EGG_GROWING_ANIMATION "graphics/Effects/GrowingEgg/"
#define BABY_GROWING_ANIMATION "graphics/Effects/GrowingBaby/"
//Dark screen file
#define DARK_SCREEN "graphics/Effects/DarkScreen.png"
//Egg select effect file
#define SELECT_EFFECT "graphics/Effects/sparkleChoise.png"

//Toys information
#define FIRST_TOY_EFFECT 8
//Toys animation
#define RIGHT_POST_ANIMATION "graphics/Toys/rightPost.png"
#define LEFT_POST_ANIMATION "graphics/Toys/leftPost.png"
#define SWING_ANIMATION "graphics/Toys/Swing"
#define BALL_ANIMATION "graphics/Toys/Ball"
#define CAR_ANIMATION "graphics/Toys/Car"

//Food animation
#define MILK_ANIMATION "graphics/Food/milk"
#define STRAWBERRY_ANIMATION "graphics/Food/strawberry"
#define BURGER_ANIMATION "graphics/Food/burger"
#define PIZZA_ANIMATION "graphics/Food/pizza"
#define CHOCOLATE_ANIMATION "graphics/Food/chocolate"
#define SALAD_ANIMATION "graphics/Food/salad"

//Menu information
#define EXIT_MENU 6
//Menu folders
#define FOOD_MENU "graphics/Buttons/Food/"
#define TOY_MENU "graphics/Buttons/Toys/"

//TicTacToe information
#define ROW_PIECES 3
#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92
//TicTacToe files
#define X_PIECE_FILEPATH "graphics/Toys/x.png"
#define O_PIECE_FILEPATH "graphics/Toys/o.png"
#define WINNING_PIECE_FILEPATH "graphics/Toys/rightPost.png"
#define LOOSE_PIECE_FILEPATH "graphics/Toys/rightPost.png"
#define GRID_SPRITE_FILEPATH "graphics/Toys/block.png"

//Pam's speech arrays
const std::string SELECT_PAM_ARRAY [5] = {
	"Hello!\n\nMy name is Pam and I \nLive right next door.\nI'm going on a \nVacation and I can \nTake only 3 of my \nPets with me...",
	"\nI need your help\nWith taking care\nFor one of them\nCan you do that?..." ,
	"\nThank you for helping\nYou are the best!\nI have to be honest\nAnd say they are\nNot usual animals...",
	"They are creatures\nCalled Noonis.\nYou can feed, bath \nThem and play with \nThem and you can\nAlso teach them \nHow to speak! ...",
	"For now it's only in\nIt's egg stage.\nIt will grow slowly!\nI'm sure you two will\nHave a good time \nTogether!\nPlease go next\nAnd select your Nooni..."
};
const std::string EGG_PAM_ARRAY[6] = {
	"Welcome to your\nNooni's room!",
	"You can see your Nooni\nEgg on the carpet...",
	"The heart above him is\nA reflection of your \nNooni's needs...",
	"On the left side of the\nScreen you can see\nYour Nooni's needs...",
	"For now his only need\nIs being petted...",
	"Just press on your\nNooni as long as you \nWant to pet him!..."
};
const std::string BABY_PAM_ARRAY[9] = { 
		"Good news!\nYour Nooni just grew \nInto a baby...",
		"On the left side of the\nScreen you can see\nHis new needs...",
		"His needs are :\nBeing petted, eat, sleep, \nTake a bath and play...",
		"Now you can press on \nThe bed to let him \nSleep...",
		"You can press on the \nBath to let him take \nA bath...",
		"You can press on the\nRefrigerator to feed \nHim...",
		"You can press on the\nToy Box to play with\nHim...",
		"You can teach him how \nTo speak by pressing\nSpeech button...",
		"Have fun you two!\nJust don't forget taking\nCare for his needs..." 
};
const std::string ADULT_PAM_ARRAY[4] = {
		"Good news!\nYour Nooni just grew \nInto an adult...",
		"Now the refrigerator is full\nWith new different kind of\nFood..",
		"Now you can teach him\nMore new words at the \nSpeaking class...",
		"I'm going to come back as \nSoom as I can, please keep\nTaking care for him..."
};
const std::string SPEAK_PAM_ARRAY[6] = {
		"Welcome to the \nSpeaking class...",
		"This is the place where\nYour nooni can learn new\nWords and speak...",
		"The words are blocked.\nIn order to open them\nAnd teach your nooni...",
		"Please press on\nThe locked buttons...",
		"Please give your nooni as\nMuch time as he needs\nTo complete his learning...",
		"After finishing his learning\nYou can press on the word \nButton and he will say it..."
};
const std::string LOOSE_PAM_ARRAY[1] = {
		"Hello again, neighbor!\nI heard my Nooni is very \nSick so I hurried back\nSo I can take care for him.\nWe can try next time..."
};
const std::string WIN_PAM_ARRAY[1] = {
		"Hello again, neighbor!\nThank you for the good \nTreatment you gave \nMy Nooni, now I'm going back \nHome, you can take care \nOf him again next time!..."
};
const std::string WORDS[12] = {
	"Nooni", "Hello", "Mommy", "Daddy", "Happy", "Sad",
	"I ♥ U", "I can talk", "My room", "You are pretty",
	"Let's play", "I love pizza"
};

enum NooniName {
	Angel,
	Coco,
	Fifi,
	Boo
};

enum moods {
	greenMood = 10,
	yellowMood = 7,
	redMood = 3,
	blackMood = 0
};

enum age {
	egg,
	baby,
	adult
};

enum food {
	Milk,
	Strawberry,
	Salad,
	Burger,
	Pizza,
	Chocolate,
};

enum actions {
	beingPet, eat, sleep, takingBath, play, growing, talk, intro, stand, openRefrigerator, openBox, GoOtherState
};

enum accessories {
	refrigerator, bed, bath, table, toyBox
};

enum pamTalking {
	introduce,
	eggExplanation,
	babyExplanation,
	adultExplanation,
	speakExplanation,
	loose,
	win
};

enum effects {
	sleepEffect,
	bathEffect,
	milkEffect,
	strawberryEffect,
	saladEffect,
	burgerEffect,
	pizzaEffect,
	chocolateEffect,
	ballEffect,
	carEffect,
	beingPettedEffect,
	growingEggEffect,
	growingBabyEffect
};

enum games {
	ball,
	car,
	tic_tac_toe
};

enum backgroundSoundsType {
	mainSound,
	LearningSound
};

enum actionSoundsType {
	pettingSound,
	showerSound,
	eatingSound,
	growingSound,
	sleepingSound,
	playingSound
};

enum gameSoundsType {
	mouseClickSound,
	happyPetSound
};