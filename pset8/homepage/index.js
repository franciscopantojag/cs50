const closeButtonSkillForm = document.getElementById("closeButtonSkillForm");
const skillForm = document.getElementById("skillForm");
const skillNameInput = document.getElementById("skillNameInput");
const skillTypeControlSelect = document.getElementById(
  "skillTypeControlSelect"
);

const overallSkillsUl = document.getElementById("overallSkillsUl");
const mainTechSkillsUl = document.getElementById("mainTechSkillsUl");
const skillsTypes = ["Main Tech", "Overall"];

const inputElementValidationEmpty = (element) => {
  if (element.value.trim() === "") {
    element.classList.add("is-invalid");
  } else {
    element.classList.remove("is-invalid");
  }
};
skillNameInput.addEventListener("input", (e) => {
  inputElementValidationEmpty(e.target);
});

skillForm.onsubmit = (e) => {
  e.preventDefault();
  if (skillNameInput.value.trim() === "") {
    skillNameInput.classList.add("is-invalid");
    return;
  } else {
    skillNameInput.classList.remove("is-invalid");
  }
  const liElement = document.createElement("li");
  const textLi = document.createTextNode(skillNameInput.value);
  liElement.appendChild(textLi);
  if (skillTypeControlSelect.value === "Main Tech") {
    mainTechSkillsUl.appendChild(liElement);
  } else if (skillTypeControlSelect.value === "Overall") {
    overallSkillsUl.appendChild(liElement);
  }

  closeButtonSkillForm.click();
};
