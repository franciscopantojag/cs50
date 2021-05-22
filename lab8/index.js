const multipleChoiceButtons = document.querySelectorAll(
  "div[id='multipleChoice'][class='section'] button"
);
const multipleChoiceFeedback = document.querySelector(
  "div[id='multipleChoice'][class='section'] .questionFeedback"
);
const freeResponseButton = document.querySelector(
  "div[id='freeResponse'][class='section'] button"
);
const freeResponseInputNumber = document.querySelector(
  "div[id='freeResponse'][class='section'] input[type='number']"
);
const freeResponseFeedback = document.querySelector(
  "div[id='freeResponse'][class='section'] .questionFeedback"
);
const freeResponseForm = document.querySelector(
  "div[id='freeResponse'][class='section'] form"
);
const correctAnswers = [
  {
    section: "freeResponse",
    answer: "200",
  },
  {
    section: "multipleChoice",
    answer: "33 million",
  },
];
const isEmpty = (str) => {
  if (str.toString().trim() === "") {
    return true;
  }
  return false;
};

const activateFeedback = (element, correct = false, empty = false) => {
  element.classList.remove("animationAppear");
  setTimeout(() => {
    element.style.display = "block";
    element.classList.add("animationAppear");
  }, 0);

  if (empty) {
    element.innerHTML = "Please enter an answer";
  } else if (correct && !empty) {
    element.innerHTML = "Correct";
    element.style.color = correctColor;
  } else if (!correct && !empty) {
    element.innerHTML = "Incorrect";
    element.style.color = incorrectColor;
  }
};
const toggleStyle = (element, correct = true) => {
  if (correct) {
    element.style.backgroundColor = correctColor;
  } else {
    element.style.backgroundColor = incorrectColor;
  }
  element.style.color = "white";
  element.style.opacity = 0.7;
};

const correctColor = "teal";
const incorrectColor = "#e36060";

const disableButton = (button) => {
  button.disabled = true;
  button.style.cursor = "default";
  button.style.backgroundColor = "#d9edff";
};
const disableMultipleChoiceButtons = () => {
  multipleChoiceButtons.forEach((button) => {
    disableButton(button);
  });
};
multipleChoiceButtons.forEach((button, index) => {
  button.onclick = (e) => {
    disableMultipleChoiceButtons();
    if (
      button.innerHTML ===
      correctAnswers.find((obj) => obj.section === "multipleChoice")?.answer
    ) {
      toggleStyle(e.target, true);
      activateFeedback(multipleChoiceFeedback, true);
    } else {
      toggleStyle(e.target, false);
      activateFeedback(multipleChoiceFeedback, false);
    }
  };
});
freeResponseForm.onsubmit = (e) => {
  e.preventDefault();
};
freeResponseButton.onclick = (e) => {
  if (isEmpty(freeResponseInputNumber.value)) {
    activateFeedback(freeResponseFeedback, false, true);
  } else {
    disableButton(e.target);
    freeResponseInputNumber.disabled = true;
    if (
      freeResponseInputNumber.value.trim() ===
      correctAnswers.find((obj) => obj.section === "freeResponse")?.answer
    ) {
      toggleStyle(freeResponseInputNumber, true);
      activateFeedback(freeResponseFeedback, true);
    } else {
      toggleStyle(freeResponseInputNumber, false);
      activateFeedback(freeResponseFeedback, false);
    }
  }
};
