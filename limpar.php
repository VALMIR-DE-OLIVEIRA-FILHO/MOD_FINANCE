<?php
require_once "classes/LancamentoManager.php";

$manager = new LancamentoManager("data/lancamentos.txt");
$manager->limpar();

header("Location: index.php");
exit;
