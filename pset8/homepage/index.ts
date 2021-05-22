const closeButtonSkillForm = document.getElementById(
  "closeButtonSkillForm"
) as HTMLButtonElement;
const skillForm = document.getElementById("skillForm") as HTMLFormElement;
const skillNameInput = document.getElementById(
  "skillNameInput"
) as HTMLInputElement;
const skillTypeControlSelect = document.getElementById(
  "skillTypeControlSelect"
) as HTMLSelectElement;

const overallSkillsUl = document.getElementById(
  "overallSkillsUl"
) as HTMLUListElement;
const mainTechSkillsUl = document.getElementById(
  "mainTechSkillsUl"
) as HTMLUListElement;
const skillsTypes = ["Main Tech", "Overall"];

const inputElementValidationEmpty = (element: HTMLInputElement) => {
  if (element.value.trim() === "") {
    element.classList.add("is-invalid");
  } else {
    element.classList.remove("is-invalid");
  }
};
skillNameInput.addEventListener("input", (e) => {
  inputElementValidationEmpty(e.target as HTMLInputElement);
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
