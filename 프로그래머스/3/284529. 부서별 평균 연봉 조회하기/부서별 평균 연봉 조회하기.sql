-- 코드를 작성해주세요
SELECT A.DEPT_ID, A.DEPT_NAME_EN, ROUND(AVG(B.SAL)) AS AVG_SAL FROM HR_DEPARTMENT AS A JOIN HR_EMPLOYEES AS B ON A.DEPT_ID=B.DEPT_ID GROUP BY B.DEPT_ID ORDER BY AVG_SAL DESC;